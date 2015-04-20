#include<iostream>
#include<tuple>
#include"authenticator.hh"

int main(int argc, char** argv){
  std::fstream inFile("user", std::fstream::in | std::fstream::out);
  authenticator auth(inFile);
  std::string user;

  unsigned int i = 0;
  for(auto it = auth.users.begin(); it != auth.users.end(); ++it){
    std::cout << std::get<0>(*it) << std::endl;
    std::cout << std::get<1>(*it) << std::endl;
    std::cout << std::endl;
  }
  while(true){
    int opt;
    std::string name;
    std::string pass;

    std::cout << "What would you like to do?\t" << std::endl;
    std::cout << "1.\tAdd a user" << std::endl;
    std::cout << "2.\tRemove a user" << std::endl;
    std::cin >> opt;
    if(std::cin.fail()){
      continue;
    }
    std::cout << "Please enter username and password for user:" << std::endl;
    std::cout << "username:\t";
    std::cin >> name;
    std::cout << "password:\t";
    auth.setStdinEcho(false);
    std::cin >> pass;
    auth.setStdinEcho(true);
    if(opt == 1){
      auth.mkUser(name, pass);
    }
    if(opt == 2){
      std::cout << "Please implement" << std::endl;
      //auth.rmUser(name, pass);
    }
  }
  return 0;
}

