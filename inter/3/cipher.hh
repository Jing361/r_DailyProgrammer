#ifndef __CIPHER_H__
#define __CIPHER_H__

#include<array>
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

