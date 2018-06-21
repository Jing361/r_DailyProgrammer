#include<algorithm>
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

    w.path( current.first, current.second, location::OPEN );
  }

  return w;
}

world
maze::generate( unsigned int x, unsigned int y, unsigned int z ){
  return generate( {x, y, z} );
}

world
maze::gen_kruskal( const size_pair& size ){
  using wall = vector<position>;
  world w( size );
  vector<wall> walls;
  vector<set<position> > cells;

  // initialize
  for( unsigned int i = 0; i < size.x; ++i ){
    for( unsigned int j = 0; j < size.y; ++j ){
      for( unsigned int k = 0; k < size.z; ++k ){
        position pos( i, j, k );

        cells.push_back( {pos} );

        auto next = filter( generate_next( pos ), size );
        for( auto spot : next ){
          wall w;

          w.push_back( pos );
          w.push_back( spot );
          sort( w.begin(), w.end() );

          walls.emplace_back( w );
        }
      }
    }
  }

  random_device rd;
  mt19937 generator( rd() );
  shuffle( walls.begin(), walls.end(), generator );
  for( auto wal : walls ){
    //if cells are members of distinct sets
      //remove wall
      w.path( wal[0], wal[1], location::OPEN );

      //merge sets
      // find sets to be merged
      auto f = find_if( cells.begin(), cells.end(),
        [wal]( const set<position>& s ){
          return s.count( wal[0] ) > 0;
        }
      );
      auto l = find_if( cells.begin(), cells.end(),
        [wal]( const set<position>& s ){
          return s.count( wal[1] ) > 0;
        }
      );

      // merge the sets, and remove unneeded one
      //merge is a new member
      //f->merge( *l );
      set<position> destination;
      set_union( f->begin(), f->end(), l->begin(), l->end(), inserter( destination, destination.begin() ) );
      cells.push_back( destination );
      cells.erase( f );
      cells.erase( l );
  }

  return w;
}

world
maze::gen_kruskal( unsigned int x, unsigned int y, unsigned int z ){
  return gen_kruskal( {x, y, z} );
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

