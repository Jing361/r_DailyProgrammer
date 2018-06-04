#include"cipher.hh"

cipher::cipher( unsigned int cyp ){
  crypt = cyp;
}

char cipher::encypher( char c ){
  c = std::toupper( c, loc );

  return ( ( ( int( c ) - 'A' ) + crypt ) % 26 ) + 'A';
}

char cipher::decypher( char c ){
  c = std::toupper( c, loc );

  return ( ( ( int( c ) - 'A' ) - crypt ) % 26 ) + 'A';
}

