#include<iostream>
#include<string>
#include<fstream>

int main(){
  std::ofstream out("out.txt");
  std::string name;

  std::cout << "Name:" << std::endl;
  std::cin >> name;
  out << name;

  return 0;
}

