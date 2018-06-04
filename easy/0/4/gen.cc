#include"gen.hh"

using namespace std;

rGen::rGen( int low, int high )
  : min( low )
  , max( high + 1 ){
  srand( time( 0 ) );
}

int rGen::operator()(){
  return ( rand() % ( max - min ) ) + min;
}

