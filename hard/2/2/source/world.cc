#include<tools.hh>
#include<world.hh>

using namespace std;

world::world( size_pair p, const vector<vector<location> >& m )
  : mSize( p )
  , mMap( m ){
}

void
world::set_data( position p, location l ){
  mMap[p.x][p.y] = l;
}

world::world( const world& w )
  : world( w.mSize, w.mMap ){
}

world::world( world&& w )
  : mSize( w.mSize )
  , mMap( forward<vector<vector<location> > >( w.mMap ) ){
}

world::world( size_pair size )
  : world( translate( size ), {translate( size.x ), vector<location>( translate( size.y ) )} ){
  clear();
}

world::world( unsigned int x, unsigned int y )
  : world( {x, y}, {mSize.x, vector<location>( y )} ){
  clear();
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
  mMap = forward<vector<vector<location> > >( other.mMap );

  return *this;
}

void
world::clear(){
  for( auto& row : mMap ){
    for( auto& space : row ){
      space = location::WALL;
    }
  }
}

location&
world::operator[]( position p ){
  return mMap[translate( p.x )][translate( p.y )];
}

position
world::rand_edge() const{
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

size_pair
world::size() const{
  return {( mSize.x - 1 ) / 2, ( mSize.y - 1 ) / 2};
}

void
world::path( const position& a, const position& b ){
  auto tran_a = translate( a );
  auto tran_b = translate( b );
  position temp( ( tran_a.x + tran_b.x ) / 2, ( tran_a.y + tran_b.y ) / 2 );

  set_data( tran_a, location::OPEN );
  set_data( tran_b, location::OPEN );
  set_data( temp, location::OPEN );
}

void
world::route( const position& a, const position& b ){
  auto tran_a = translate( a );
  auto tran_b = translate( b );
  position mid( ( tran_a.x + tran_b.x ) / 2, ( tran_a.y + tran_b.y ) / 2 );

  set_data( tran_a, location::PATH );
  set_data( tran_b, location::PATH );
  set_data( mid, location::PATH );
}

set<position>
world::get_next( position p ) const{
  auto unsize = untranslate( mSize );
  auto candidates = filter( generate_next( p ), unsize.x, unsize.y );
  set<position> results;
  p = translate( p );

  for( auto cand : candidates ){
    auto cand_t = translate( cand );
    position pos;
    pos.x = ( cand_t.x + p.x ) / 2;
    pos.y = ( cand_t.y + p.y ) / 2;

    if( mMap[pos.x][pos.y] != location::WALL ){
      results.insert( cand );
    }
  }

  return results;
}

