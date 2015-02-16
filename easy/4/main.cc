#include<iostream>
#include<string>
#include"gen.hh"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv){
  int low = 33;
  int high = 126;
  int len;
  rGen generator(low, high);
  string passwd;

  if(argc < 2){
    len = 10;
  } else if(argc == 2){
    len = atoi(argv[1]);
  } else {
    cout << "Invalid number of arguments." << endl;
    return 1;
  }

  for(int i = 0; i < len; ++i){
    int x = generator();
    passwd += (char)x;
  }

  cout << passwd << endl;

  return 0;
}

