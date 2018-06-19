#include<tools.hh>
#include<world.hh>

using namespace std;

world::world( size_pair p, const vector<vector<vector<location> > >& m )
  : mSize( p )
  , mMap( m ){
}

void
world::set_data( position p, location l ){
  mMap[p.z][p.y][p.x] = l;
}

world::world( const world& w )
  : world( w.mSize, w.mMap ){
}

world::world( world&& w )
  : mSize( w.mSize )
  , mMap( forward<vector<vector<vector<location> > > >( w.mMap ) ){
}

world::world( size_pair size )
  : world( translate( size ), {translate( size.z ), vector<vector<location> >( {translate( size.y ), vector<location>( translate( size.x ) )} )} ){
  clear();
}

world::world( unsigned int x, unsigned int y, unsigned int z )
  : world( size_pair( x, y, z ) ){
}

world&
world::operator=( const world& other ){
  mSize = other.mSize;
  mMap = other.mMap;

  return *this;
}

world&
world::operator=( world&& other ){
  mSize = other.mSize;
  mMap = forward<vector<vector<vector<location> > > >( other.mMap );

  return *this;
}

void
world::clear(){
  for( auto& layer : mMap ){
    for( auto& row : layer ){
      for( auto& space : row ){
        space = location::WALL;
      }
    }
  }
}

location&
world::operator[]( position p ){
  return mMap[translate( p.z )][translate( p.y )][translate( p.x )];
}

const location&
world::operator[]( position p ) const{
  return (*this)[p];
}

position
world::rand_edge() const{
  random_device rd;
  mt19937 rate( rd() );
  int randX;
  int randY;
  int randZ;

  if( coin_flip() ){
    uniform_int_distribution<> gene( 0, untranslate( mSize.x ) - 1 );
    randX = gene( rate );
    randY = coin_flip() ? 0 : untranslate( mSize.y ) - 1;
  } else {
    uniform_int_distribution<> gene( 0, untranslate( mSize.y ) - 1 );
    randY = gene( rate );
    randX = coin_flip() ? 0 : untranslate( mSize.x ) - 1;
  }

  randZ = coin_flip() ? 0 : untranslate( mSize.z ) - 1;

  return {randX, randY, randZ};
}

size_pair
world::size() const{
  return {untranslate( mSize.x ), untranslate( mSize.y ), untranslate( mSize.z )};
}

void
world::path( const position& a, const position& b, location l ){
  auto tran_a = translate( a );
  auto tran_b = translate( b );
  position temp( ( tran_a.x + tran_b.x ) / 2,
                 ( tran_a.y + tran_b.y ) / 2,
                 ( tran_a.z + tran_b.z ) / 2 );

  set_data( tran_a, l );
  set_data( tran_b, l );
  set_data( temp, l );
}

set<position>
world::get_next( position p ) const{
  auto unsize = untranslate( mSize );
  auto candidates = filter( generate_next( p ), unsize );
  set<position> results;
  p = translate( p );

  for( auto cand : candidates ){
    auto cand_t = translate( cand );
    position pos;
    pos.x = ( cand_t.x + p.x ) / 2;
    pos.y = ( cand_t.y + p.y ) / 2;
    pos.z = ( cand_t.z + p.z ) / 2;

    if( mMap[pos.z][pos.y][pos.x] != location::WALL ){
      results.insert( cand );
    }
  }

  return results;
}

