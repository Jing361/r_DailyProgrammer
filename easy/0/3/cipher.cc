#include"cipher.hh"

cipher::cipher(unsigned int cyp){
  crypt = cyp;
}

char cipher::encypher(char c){
  c = std::toupper(c, loc);

  return (( (((int)c) - 65) + crypt) % 26) + 65;
}

char cipher::decypher(char c){
  c = std::toupper(c, loc);

  return (( (((int)c) - 65) - crypt) % 26) + 65;
}

