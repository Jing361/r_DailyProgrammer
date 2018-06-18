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

  xandy()
    : xandy( 0, 0 ){
  }

  xandy( T X, T Y )
    : x( X )
    , y( Y ){
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
    }
  }

  bool
  operator==( const xandy& other ) const{
    return x == other.x && y == other.y;
  }

  bool
  operator<( const xandy& other ) const{
    if( x == other.x ){
      return y < other.y;
    } else {
      return x < other.x;
    }
  }
};

using position = xandy<int>;
using size_pair = xandy<unsigned int>;

std::set<position>
generate_next( position p );

std::set<position>
filter( const std::set<position>& input, int filtX, int filtY );

bool
coin_flip();

template<typename T>
T
translate( T a ){
  return ( a * 2 ) + 1;
}

template<typename T>
xandy<T>
translate( xandy<T> a ){
  return {translate( a.x ), translate( a.y )};
}

template<typename T>
T
untranslate( T a ){
  return ( a - 1 ) / 2;
}

template<typename T>
xandy<T>
untranslate( xandy<T> a ){
  return {untranslate( a.x ), untranslate( a.y )};
}

#endif

