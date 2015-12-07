#include<iostream>
#include<string>

int main(){
  std::string prompt;

  std::cin >> prompt;

  if(prompt == "Name:"){
    std::cout << "Chris" << std::endl;
  } else {
    std::cout << "shit" <<std::endl;
  }

  return 0;
}

