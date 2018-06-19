#ifndef __WORLD_HH__
#define __WORLD_HH__

#include<set>
#include<vector>
#include<utility>
#include<random>

#include<tools.hh>

class world{
private:
  size_pair mSize;
  std::vector<std::vector<std::vector<location> > > mMap;

  world( size_pair p, const std::vector<std::vector<std::vector<location> > >& m );

  void
  set_data( position p, location l );

public:
  world( const world& w );

  world( world&& w );

  world( size_pair size );

  world( unsigned int x, unsigned int y, unsigned int z = 1 );

  world&
  operator=( const world& other );

  world&
  operator=( world&& other );

  void
  clear();

  location&
  operator[]( position p );

  const location&
  operator[]( position p ) const;

  position
  rand_edge() const;

  size_pair
  size() const;

  template<typename OSTREAM>
  void
  print( OSTREAM& os ) const{
    for( auto pillar : mMap ){
      for( auto row : pillar ){
        for( auto space : row ){
          if( space == location::OPEN ){
            os << ' ';
          } else if( space == location::WALL ){
            os << '+';
          } else if( space == location::START ){
            os << 'S';
          } else if( space == location::END ){
            os << 'E';
          } else if( space == location::PATH ){
            os << '@';
          }
        }
        os << '\n';
      }
      os << '\n';
    }
    os << '\n';
  }

  void
  path( const position& a, const position& b );

  void
  route( const position& a, const position& b );

  std::set<position>
  get_next( position p ) const;
};

#endif

