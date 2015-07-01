#include<iostream>
#include<string>
#include<sstream>

int main(){
  std::string input;
  std::string number;
  unsigned int test;
  bool good;

  do{
    std::stringstream ss;

    std::cout << "Input an integer\t" << std::flush;
    std::cin >> input;
    ss << input;
    good = (ss >> test);
  }while(!good && (std::cout << "Try again!  We need an integer." << std::endl));
  std::cout << "FINALLY\t" << test << std::endl;

  return 0;
}

