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

template<typename T>
struct xandy{
  T x;
  T y;

  xandy()
    : xandy( 0, 0 ){
  }

  xandy( T X, T Y )
    : x( X )
    , y( Y ){
  }

  T&
  operator[]( unsigned int idx ){
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
  operator==( const xandy& other ) const{
    return x == other.x && y == other.y;
  }

  bool
  operator<( const xandy& other ) const{
    if( x == other.x ){
      return y < other.y;
    } else {
      return x < other.x;
    }
  }
};

using position = xandy<int>;
using size_pair = xandy<unsigned int>;

bool
coin_flip(){
  random_device rd;
  mt19937 rate( rd() );
  uniform_int_distribution<> gene( 0, 1 );

  return gene( rate ) ? 0 : 1;
}

template<typename T>
T
translate( T a ){
  return ( a * 2 ) + 1;
}

template<typename T>
xandy<T>
translate( xandy<T> a ){
  return {translate( a.x ), translate( a.y )};
}

class world{
private:
  size_pair mSize;
  vector<vector<location> > mMap;

  world( size_pair p, const vector<vector<location> >& m )
    : mSize( p )
    , mMap( m ){
  }

  void
  set( position p, location l ){
    mMap[p.x][p.y] = l;
  }

public:
  world( const world& w )
    : world( w.mSize, w.mMap ){
  }

  world( world&& w )
    : mSize( w.mSize )
    , mMap( forward<vector<vector<location> > >( w.mMap ) ){
  }

  world( size_pair size )
    : world( translate( size ), {translate( size.x ), vector<location>( translate( size.y ) )} ){
    clear();
  }

  world( unsigned int x, unsigned int y )
    : world( {x, y}, {mSize.x, vector<location>( y )} ){
    clear();
  }

  world&
  operator=( const world& other ){
    mSize = other.mSize;
    mMap = other.mMap;

    return *this;
  }

  world&
  operator=( world&& other ){
    mSize = other.mSize;
    mMap = forward<vector<vector<location> > >( other.mMap );

    return *this;
  }

  void
  clear(){
    for( auto& row : mMap ){
      for( auto& space : row ){
        space = location::WALL;
      }
    }
  }

  location&
  operator[]( position p ){
    return mMap[translate( p.x )][translate( p.y )];
  }

  position
  rand_edge() const{
    random_device rd;
    mt19937 rate( rd() );
    int randX;
    int randY;

    if( coin_flip() ){
      uniform_int_distribution<> gene( 0, ( ( mSize.x - 1 ) / 2 ) - 1 );
      randX = gene( rate );
      randY = coin_flip() ? 0 : ( ( mSize.y - 1 ) / 2 ) - 1 - 0;
    } else {
      uniform_int_distribution<> gene( 0, ( ( mSize.y - 1 ) / 2 ) - 1 );
      randY = gene( rate );
      randX = coin_flip() ? 0 : ( ( mSize.x - 1 ) / 2 ) - 1 - 0;
    }

    return {randX, randY};
  }

  void
  print() const{
    for( auto row : mMap ){
      for( auto space : row ){
        if( space == location::OPEN ){
          cout << ' ';
        } else if( space == location::WALL ){
          cout << '+';
        } else if( space == location::START ){
          cout << 'S';
        } else if( space == location::END ){
          cout << 'E';
        } else if( space == location::PATH ){
          cout << '@';
        }
      }
      cout << endl;
    }
    cout << endl;
  }

  void
  path( const position& a, const position& b ){
    auto tran_a = translate( a );
    auto tran_b = translate( b );
    position temp( ( tran_a.x + tran_b.x ) / 2, ( tran_a.y + tran_b.y ) / 2 );

    set( tran_a, location::OPEN );
    set( tran_b, location::OPEN );
    set( temp, location::OPEN );
  }

  void
  route( const position& a, const position& b ){
    auto tran_a = translate( a );
    auto tran_b = translate( b );
    position mid( ( tran_a.x + tran_b.x ) / 2, ( tran_a.y + tran_b.y ) / 2 );

    set( tran_a, location::PATH );
    set( tran_b, location::PATH );
    set( mid, location::PATH );
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
  generate( const size_pair& size ){
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
  generate( unsigned int x, unsigned int y ){
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

