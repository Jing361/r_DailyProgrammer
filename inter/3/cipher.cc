#include"cipher.hh"

cipher::cipher(char* c):cipher(std::string(c)){
}

//Establish cipher alphabet using cip as cypher word to start.
cipher::cipher(std::string cip){
  bool match;

  for(auto it = cip.begin(); it != cip.end(); ++it){
    *this += std::toupper(*it, this->loc);
  }

  for(int i = 0; i < 26; ++i){
    match = false;
    for(auto it = this->begin(); it != this->end(); ++it){
      if( ((char)(i + 65)) == *it){
        match = true;
        break;
      }
    }
    if(!match){
      *this += (char)(i + 65);
    }
  }
}

char cipher::encypher(char c){
  c = std::toupper(c, this->loc);

  return (*this)[((int)c - 65)];

}

