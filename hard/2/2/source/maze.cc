#include<set>
#include<stack>
#include<utility>

#include<maze.hh>
#include<world.hh>

using namespace std;

world
maze::generate( const size_pair& size ){
  world w( size );
  set<position> explored;
  set<pair<position, position> > frontier;
  position start = {0, 0, 0};

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

    auto next = filter( generate_next( current.second ), size );
    for( auto pos : next ){
      frontier.emplace( current.second, pos );
    }

    w.path( current.first, current.second );
  }

  return w;
}

world
maze::generate( unsigned int x, unsigned int y, unsigned int z ){
  return generate( {x, y, z} );
}

set<path>
maze::solve( const world& w_in, position start, position end ){
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
maze::solve( const world& w_in, int start_x, int start_y, int end_x, int end_y ){
  return solve( w_in, {start_x, start_y}, {end_x, end_y} );
}

