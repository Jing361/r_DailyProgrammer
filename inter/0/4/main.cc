#include<iostream>
#include<string>
#include"calculator.hh"

int main(int argc, char** argv){
  std::string start = "3+4*2/4";
  calculator calc(start);

  std::cout << calc.evaluate() << std::endl;

  return 0;
}

