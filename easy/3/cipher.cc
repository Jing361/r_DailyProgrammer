#include"cipher.hh"

cipher::cipher(unsigned int cyp){
  this->crypt = cyp;
}

char cipher::encypher(char c){
  c = std::toupper(c, this->loc);

  return (( (((int)c) - 65) + this->crypt) % 26) + 65;
}

char cipher::decypher(char c){
  c = std::toupper(c, this->loc);

  return (( (((int)c) - 65) - this->crypt) % 26) + 65;
}

