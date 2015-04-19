#include<iostream>
#include<vector>
#include<string>

bool authenticate(){
  std::string username = "abc";
  std::string password = "123";
  std::string s;

  std::cout << "username:\t";
  std::cin >> s;
  if(std::cin.fail()){
    std::cerr << "format error!" << std::endl;
    return false;
  }
  if(s != username){
    std::cout << "invalid username" << std::endl;
    return false;
  }

  std::cout << "password:\t";
  std::cin >> s;
  if(std::cin.fail()){
    std::cerr << "format error!" << std::endl;
    return false;
  }
  if(s != password){
    std::cout << "invalid password" << std::endl;
    return false;
  }
  return true;
}

int main(int argc, char** argv){
  if(authenticate()){
    std::cout << "you win!" << std::endl;
  }

  return 0;
}

