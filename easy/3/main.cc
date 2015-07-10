#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include"cipher.hh"

//TODO: Add input type checking.
//TODO: Establish clearer differences between encrypt and decrypt.
//          Whether the same number used to decrypt is used to encrypt etc
//          If not same number then would be 26 - crypt
int main(int argc, char** argv){
  int crypt;
  bool encrypting;

  if(argc < 3){
    std::cout << "Not enough arguments." << std::endl;
    std::cout << "Use as " << argv[0] << " [key] [message]" << std::endl;
    std::cout << "[key] is interpretted as a number, and [message] as text" << std::endl;
    return 1;
  }

  std::string msg(argv[2]);
  std::string name(argv[0]);
  std::string result;
  crypt = atoi(argv[1]);
  cipher cypher(crypt);

  if(name[name.length() - 7] == 'e'){
    encrypting = true;
  } else if(name[name.length() - 7] == 'd'){
    encrypting = false;
  }else {
    std::cout << "Invalid calling name" << std::endl;
    return 2;
  }

  for(auto it = msg.begin(); it != msg.end(); ++it){
    if(encrypting){
      result += cypher.encypher(*it);
    }else {
      result += cypher.decypher(*it);
    }
  }

  std::cout << result << std::endl;
  return 0;
}

