#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

// options:
//  direction:
//    forward
//    backward
//  justification:
//    left
//    right
int main( int argc, char** argv ){
  if( argc != 2 && argc != 4 ){
    return 1;
  }

  int rowcount;
  bool forward = true;
  bool left = true;

  stringstream ss( argv[1] );
  ss >> rowcount;

  if( argc == 4 ){
    stringstream ss( argv[2] );
    ss >> forward;

    stringstream st( argv[3] );
    st >> left;
  }

  int rowsize = 1;
  int padsize = 0;
  int maxpad;
  maxpad = pow( 2, rowsize );
  if( forward ){
    for( int i = 0; i < rowcount; ++i ){
      string line( rowsize, '@' );

      if( !left ){
        padsize = maxpad - line.size();
      }
      string padding( padsize, ' ' );

      cout << padding << line << '\n';
      rowsize *= 2;
    }
  } else {
    for( int i = rowcount; i > 0; --i ){
      string line( rowsize, '@' );

      if( !left ){
        padsize = maxpad - line.size();
      }
      string padding( padsize, ' ' );

      cout << padding << line << '\n';
      rowsize /= 2;
    }
  }

  return 0;
}

