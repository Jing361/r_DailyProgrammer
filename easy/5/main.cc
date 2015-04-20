#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"authenticator.hh"

int main(int argc, char** argv){
  std::fstream inFile("user", std::fstream::in);
  authenticator auth(inFile);

  if(!auth.readUser()){
    std::cout << "you lose!" << std::endl;
    return 1;
  } else {
    std::cout << "you win!" << std::endl;
    //run normal stuff here.
  }

  return 0;
}

