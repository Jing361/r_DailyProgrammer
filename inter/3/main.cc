#include<iostream>
#include<queue>
#include<array>
#include"cipher.hh"

//TODO: Establish decryption.
int main(int argc, char** argv){
  if(argc < 3){
    std::cout << "Not enough arguments." << std::endl;
    std::cout << "Use as " << argv[0] << " [key] [message]" << std::endl;
    std::cout << "[key] is interpretted as a number, and [message] as text" << std::endl;
    return 1;
  }

  cipher cypher(argv[1]);
  std::string msg(argv[2]);
  std::string result;

  for(auto it = msg.begin(); it != msg.end(); ++it){
    result += cypher.encypher(*it);
  }

  std::cout << result << std::endl;
  return 0;
}

