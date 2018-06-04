#ifndef __CIPHER_H__
#define __CIPHER_H__

#include<locale>

class cipher{
private:
  std::locale loc;
  unsigned int crypt;

public:
  cipher( unsigned int cyp );

  char encypher( char c );
  char decypher( char c );
};

#endif

