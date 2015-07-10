#include<iostream>
#include<string>
#include"gen.hh"

int main(int argc, char** argv){
  int low = 33;
  int high = 126;
  int len;
  rGen generator(low, high);
  std::string passwd;

  if(argc < 2){
    len = 10;
  } else if(argc == 2){
    len = atoi(argv[1]);
  } else {
    std::cout << "Invalid number of arguments." << std::endl;
    return 1;
  }

  for(int i = 0; i < len; ++i){
    int x = generator();
    passwd += (char)x;
  }

  std::cout << passwd << std::endl;

  return 0;
}

