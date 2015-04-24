#include<iostream>
#include<tuple>
#include<limits>
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

  int opt;
  while(true){
    while(std::cout << "What would you like to do?\t\n"
                    << "1.\tAdd a user\n"
                    << "2.\tRemove a user\n"
                    << "3.\tFinish\n" &&
        (!(std::cin >> opt) || opt < 1 || opt > 3)){
      std::cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input\n";
    }
    std::string name;
    std::string pass;

    if(opt < 3){
      std::cout << "Please enter username and password for user:" << std::endl;
      std::cout << "username:\t";
      std::cin >> name;
      std::cout << "password:\t";
      auth.setStdinEcho(false);
      std::cin >> pass;
      auth.setStdinEcho(true);
    }
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

