#include<random>

#include<tools.hh>

using namespace std;

bool
coin_flip(){
  random_device rd;
  mt19937 rate( rd() );
  uniform_int_distribution<> gene( 0, 1 );

  return gene( rate ) ? 0 : 1;
}

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

