#include<algorithm>
#include<iostream>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<iterator>

#include<tools.hh>
#include<world.hh>

using namespace std;

class maze_generator{
public:
  world
  generate( const size_pair& size ){
    world w( size );
    set<position> explored;
    set<pair<position, position> > frontier;
    position start = {0, 0};

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

    return w;
  }

  world
  generate( unsigned int x, unsigned int y ){
    return generate( {x, y} );
  }
};

using path = vector<position>;

class maze_solver{
public:
  set<path>
  solve( const world& w_in, position start, position end ) const{
    world w( w_in );
    stack<pair<path,
               set<position> > > frontier;
    set<path> answers;

    frontier.push( {{start}, {start}} );

    while( !frontier.empty() ){
      auto current = frontier.top();
      auto route    = current.first;
      auto explored = current.second;

      frontier.pop();

      // collect answers
      if( route.back() == end ){
        answers.emplace( route );//move?

        continue;
      }

      explored.emplace( route.back() );

      auto next = w.get_next( route.back() );
      for( auto pos : next ){
        // don't repeat
        if( explored.count( pos ) == 0 ){
          auto temp = route;

          temp.emplace_back( pos );
          frontier.emplace( temp, explored );// move temp?
        }
      }
    }

    return answers;
  }

  set<path>
  solve( const world& w_in, int start_x, int start_y, int end_x, int end_y ) const{
    return solve( w_in, {start_x, start_y}, {end_x, end_y} );
  }
};

int main(){
  maze_generator mg;
  maze_solver ms;
  world w = mg.generate( 7, 7 );
  position start = w.rand_edge();
  position end   = w.rand_edge();

  w[start] = location::START;
  w[end]   = location::END;

  w.print( cout );
  auto answers = ms.solve( w, start, end );

  auto shortest = *min_element( answers.begin(), answers.end(),
    []( const path& r1, const path& r2 ){
      return r1.size() < r2.size();
    }
  );

  for( unsigned int i = 0, j = 1; j < shortest.size(); ++i, ++j ){
    w.route( shortest[i], shortest[j] );
  }
  w.print( cout );

  return 0;
}

