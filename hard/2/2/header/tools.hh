#ifndef __TOOLS_HH__
#define __TOOLS_HH__

#include<set>

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
  T z;

  xandy()
    : xandy( 0, 0 ){
  }

  xandy( T X, T Y, T Z = 0 )
    : x( X )
    , y( Y )
    , z( Z ){
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

    case 2:
      return z;
    break;

    //! @todo throw an error
    //default:
      //throw;
    }
  }

  bool
  operator==( const xandy& other ) const{
    return x == other.x && y == other.y && z == other.z;
  }

  bool
  operator<( const xandy& other ) const{
    if( x != other.x ){
      return x < other.x;
    } else if( y != other.y ){
      return y < other.y;
    } else {
      return z < other.z;
    }
  }
};

using position = xandy<int>;
using size_pair = xandy<unsigned int>;

std::set<position>
generate_next( position p );

std::set<position>
filter( const std::set<position>& input, int filtX, int filtY, int filtZ );

std::set<position>
filter( const std::set<position>& input, const size_pair& size );

bool
coin_flip();

template<typename T>
T
translate( T a ){
  return ( a * 2 ) + 1;
}

template<typename T>
T
untranslate( T a ){
  return ( a - 1 ) / 2;
}

template<typename T>
xandy<T>
translate( xandy<T> a ){
  return {translate( a.x ), translate( a.y ), translate( a.z )};
}

template<typename T>
xandy<T>
untranslate( xandy<T> a ){
  return {untranslate( a.x ), untranslate( a.y ), untranslate( a.z )};
}

#endif

