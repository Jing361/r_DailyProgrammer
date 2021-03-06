#ifndef __MAZE_HH__
#define __MAZE_HH__

#include<set>
#include<vector>

#include<tools.hh>
#include<world.hh>

using path = std::vector<position>;

class maze{
public:
  static
  world
  generate( const size_pair& size );

  static
  world
  generate( unsigned int x, unsigned int y, unsigned int z = 1 );

  static
  world
  gen_kruskal( const size_pair& size );

  static
  world
  gen_kruskal( unsigned int x, unsigned int y, unsigned int z = 1 );

  static
  std::set<path>
  solve( const world& w_in, position start, position end );

  static
  std::set<path>
  solve( const world& w_in, int start_x, int start_y, int end_x, int end_y );
};

#endif

