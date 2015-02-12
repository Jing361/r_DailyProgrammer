#ifndef __CIPHER_H__
#define __CIPHER_H__

#include<array>
#include<string>
#include<locale>

using std::array;
using std::string;

class cipher:public string{
private:
  unsigned int crypt;
  std::locale loc;
public:
  cipher(char* c);
  cipher(string cip);
  char encypher(char c);
};

#endif

