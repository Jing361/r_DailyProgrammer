#include<iostream>
#include<map>

int main(){
  std::map<unsigned int, unsigned int> upside;
  upside.insert(std::pair<unsigned int, unsigned int>(1, 1));
  upside.insert(std::pair<unsigned int, unsigned int>(2, 2));
  upside.insert(std::pair<unsigned int, unsigned int>(5, 5));
  upside.insert(std::pair<unsigned int, unsigned int>(6, 9));
  upside.insert(std::pair<unsigned int, unsigned int>(8, 8));
  upside.insert(std::pair<unsigned int, unsigned int>(9, 6));
  upside.insert(std::pair<unsigned int, unsigned int>(0, 0));

  return 0;
}

