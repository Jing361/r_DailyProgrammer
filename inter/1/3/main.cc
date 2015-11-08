#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

int main(int argc, char** argv){
  if(argc != 2){
    std::cout << "Incorrect number of arguments." << std::endl;
    return 1;
  }
  std::fstream rev("reverse", std::fstream::out);
  std::string str(argv[1]);

  std::reverse(str.begin(), str.end());

  rev << str << std::endl;

  rev.close();
  return 0;
}

