#include<iostream>
#include<string>
#include"gen.hh"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv){
  rGen<1, 5> generator;
  cout << generator() << endl;
  return 0;
}

