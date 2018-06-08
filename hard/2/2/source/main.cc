#include<iostream>
#include<random>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<iterator>

using namespace std;

enum class location{
  OPEN,
  WALL,
  PATH,
  START,
  END,
};

struct position{
  int x;
  int y;

  position()
    : position( 0, 0 ){
  }

  position( int X, int Y )
    : x( X )
    , y( Y ){
  }

  int&
  operator[]( int idx ){
    switch( idx ){
    case 0:
      return x;
    break;

    case 1:
      return y;
    break;
    }
  }

  bool
  operator==( const position& other ) const{
    return x == other.x && y == other.y;
  }

  bool
  operator<( const position& other ) const{
    if( x == other.x ){
      return y < other.y;
    } else {
      return x < other.x;
    }
  }
};

bool
coin_flip(){
  random_device rd;
  mt19937 rate( rd() );
  uniform_int_distribution<> gene( 0, 1 );

  return gene( rate ) ? 0 : 1;
}

class world{
private:
  position size;
  location** map;

  int
  translate( int a ){
    return ( a * 2 ) + 1;
  }

  position
  translate( position a ){
    return {translate( a.x ), translate( a.y )};
  }

public:
  world( const world& w )
    : world( w.size ){
    for( int i = 0; i < size.x; ++i ){
      for( int j = 0; j < size.y; ++j ){
        map[i][j] = w.map[i][j];
      }
    }
    cout << "copy ctor:" << map << endl;
  }

  world( world&& w ){
    map = w.map;
    w.map = nullptr;
    cout << "move ctor:" << map << endl;
  }

  world( position size )
    : world( size.x, size.y ){
  }

  world( int x, int y )
    : size( translate( x ), translate( y ) ){

    map = new location*[size.x];
    for( int i = 0; i < size.x; ++i ){
      map[i] = new location[size.y];
    }
    cout << "basic ctor:" << map << endl;

    clear();
  }

  ~world(){
    cout << "dtor:" << map << endl;
    if( !map ){
      return;
    }

    for( int i = 0; i < size.x; ++i ){
      delete[] map[i];
    }
    delete[] map;
  }

  world&
  operator=( const world& other ){
    cout << "copy assign" << endl;
    for( int i = 0; i < size.x; ++i ){
      for( int j = 0; j < size.x; ++j ){
        map[i][j] = other.map[i][j];
      }
    }

    return *this;
  }

  world&
  operator=( world&& other ){
    cout << "move assign" << endl;
    map = other.map;
    other.map = nullptr;

    return *this;
  }

  void
  clear(){
    //cout << "clear:" << map << endl;
    for( int i = 0; i < size.x; ++i ){
      for( int j = 0; j < size.y; ++j ){
        map[i][j] = location::WALL;
      }
    }
  }

  location&
  operator[]( position p ){
    //cout << "access:" << map << " " << p.x << ", " << p.y << endl;
    //cout << "\t" << map[translate( p.x )] << endl;
    //cout << "\t" << &map[translate( p.x )][translate( p.y )] << endl;
    return map[translate( p.x )][translate( p.y )];
  }

  position
  rand_edge() const{
    random_device rd;
    mt19937 rate( rd() );
    int randX;
    int randY;

    if( coin_flip() ){
      uniform_int_distribution<> gene( 0, ( size.x - 1 ) / 2 );
      randX = gene( rate );
      randY = coin_flip() ? 0 : ( size.y - 1 ) / 2;
    } else {
      uniform_int_distribution<> gene( 0, ( size.y - 1 ) / 2 );
      randY = gene( rate );
      randX = coin_flip() ? 0 : ( size.x - 1 ) / 2;
    }

    return {randX, randY};
  }

  void
  print() const{
    //cout << "print:" << map << endl;
    for( int i = 0; i < size.x; ++i ){
      for( int j = 0; j < size.y; ++j ){
        if( map[i][j] == location::OPEN ){
          cout << ' ';
        } else if( map[i][j] == location::WALL ){
          cout << '+';
        } else if( map[i][j] == location::START ){
          cout << 'S';
        } else if( map[i][j] == location::END ){
          cout << 'E';
        } else if( map[i][j] == location::PATH ){
          cout << '@';
        }
      }
      cout << endl;
    }
    cout << endl;
  }

  void
  path( const position& a, const position& b ){
    (*this)[a] = location::OPEN;
    (*this)[b] = location::OPEN;
    int ax = translate( a.x );
    int ay = translate( a.y );
    int bx = translate( b.x );
    int by = translate( b.y );

    //cout << "path:" << map << endl;
    map[( ax + bx ) / 2][( ay + by ) / 2] = location::OPEN;
  }

  void
  route( const position& a, const position& b ){
    (*this)[a] = location::PATH;
    (*this)[b] = location::PATH;
    int ax = translate( a.x );
    int ay = translate( a.y );
    int bx = translate( b.x );
    int by = translate( b.y );

    //cout << "route:" << map << endl;
    map[( ax + bx ) / 2][( ay + by ) / 2] = location::PATH;
  }
};

set<position>
generate_next( position p ){
  set<position> ret;

  ret.emplace( p.x + 1, p.y );
  ret.emplace( p.x - 1, p.y );

  ret.emplace( p.x, p.y + 1 );
  ret.emplace( p.x, p.y - 1 );

  return ret;
}

set<position>
filter( const set<position>& input, int filtX, int filtY ){
  set<position> output;

  for( auto pos : input ){
    if( pos.x >= 0 && pos.x < filtX
     && pos.y >= 0 && pos.y < filtY ){
      output.emplace( pos );
    }
  }

  return output;
}

class maze_generator{
public:
  world
  generate( position size ){
    world w( size );
    set<position> explored;
    set<pair<position, position> > frontier;
    position start = w.rand_edge();
    position end = w.rand_edge();

    frontier.emplace( start, start );

    while( !frontier.empty() ){
      random_device rd;
      mt19937 rate( rd() );
      uniform_int_distribution<> gene( 0, frontier.size() - 1 );

      auto it = frontier.begin();
      advance( it, gene( rate ) );
      auto current = *it;

      frontier.erase( it );

      if( explored.count( current.second ) > 0 ){
        continue;
      }

      explored.emplace( current.second );

      auto next = filter( generate_next( current.second ), size.x, size.y );
      for( auto pos : next ){
        frontier.emplace( current.second, pos );
      }

      w.path( current.first, current.second );
    }

    w[start] = location::START;
    w[end] = location::END;

    return w;
  }

  world
  generate( int x, int y ){
    return generate( {x, y} );
  }
};

class maze_solver{
public:
  world
  solve( const world& w ) const{
    return w;
  }
};

int main(){
  maze_generator mg;
  maze_solver ms;
  mg.generate( 7, 7 ).print();
  ms.solve( mg.generate( 7, 7 ) ).print();

  return 0;
}

