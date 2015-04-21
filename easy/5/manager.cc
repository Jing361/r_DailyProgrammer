#include<iostream>
#include<tuple>
#include"authenticator.hh"

int main(){
  authenticator auth(std::string("user"));
  std::string user;

  for(auto it = auth.users.begin(); it != auth.users.end(); ++it){
    std::cout << std::get<0>(*it) << std::endl;
    std::cout << std::get<0>(std::get<1>(*it)) << std::endl;
    std::cout << std::get<1>(std::get<1>(*it)) << std::endl;
    std::cout << std::endl;
  }
  while(true){
    int opt;
    std::string name;
    std::string pass;

    std::cout << "What would you like to do?\t" << std::endl;
    std::cout << "1.\tAdd a user" << std::endl;
    std::cout << "2.\tRemove a user" << std::endl;
    std::cout << "3.\tFinish" << std::endl;
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
    } else if(opt == 2){
      auth.rmUser(name, pass);
    } else if(opt == 3){
      std::cout << "Quitting" << std::endl;
      auth.writeUsers();
      break;
    }
  }
  return 0;
}

