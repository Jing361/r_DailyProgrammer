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

  ret.emplace( p.x + 1, p.y, p.z );
  ret.emplace( p.x - 1, p.y, p.z );

  ret.emplace( p.x, p.y + 1, p.z );
  ret.emplace( p.x, p.y - 1, p.z );

  ret.emplace( p.x, p.y, p.z + 1 );
  ret.emplace( p.x, p.y, p.z - 1 );

  return ret;
}

set<position>
filter( const set<position>& input, int filtX, int filtY, int filtZ ){
  set<position> output;

  for( auto pos : input ){
    if( pos.x >= 0 && pos.x < filtX
     && pos.y >= 0 && pos.y < filtY
     && pos.z >= 0 && pos.z < filtZ ){
      output.emplace( pos );
    }
  }

  return output;
}

std::set<position>
filter( const std::set<position>& input, const size_pair& size ){
  return filter( input, size.x, size.y, size.z );
}

