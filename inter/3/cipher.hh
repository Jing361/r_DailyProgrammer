#ifndef __CIPHER_HH__
#define __CIPHER_HH__

#include<string>
#include<locale>

class cipher:private std::string{
private:
  unsigned int crypt;
  std::locale loc;
public:
  cipher(char* c);
  cipher(std::string cip);
  char encypher(char c);
};

#endif

