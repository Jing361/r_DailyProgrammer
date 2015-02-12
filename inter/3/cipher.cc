#include"cipher.hh"

cipher::cipher(char* c):cipher(string(c)){
}

cipher::cipher(string cip){
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
  unsigned int i;

  c = std::toupper(c, this->loc);

  i = 0;
  for(auto it = this->begin(); it != this->end(); ++it){
    if(*it == c){
      break;
    }
    ++i;
  }

  if(i < 13){
    i += 13;
  } else {
    i -= 13;
  }
  return (*this)[i];
}

