#include<string>
#include<iostream>
#include<algorithm>

int main(int argc, char** argv){
  if(argc != 2){
    return 1;
  }
  std::string str(argv[1]);

  std::next_permutation(str.begin(), str.end());
  std::cout << str << std::endl;

  return 0;
}

