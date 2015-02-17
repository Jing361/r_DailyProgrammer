#include<iostream>
#include<string>
#include"calculator.hh"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char** argv){
  string start = "3+4*2/4";
  calculator calc(start);

  cout << calc.evaluate() << endl;

  return 0;
}

