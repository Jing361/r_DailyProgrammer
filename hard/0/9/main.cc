#include<iostream>
#include<vector>

int main(){
  std::vector<unsigned int> pyramid;
  unsigned int row;

  while(std::cout << "Input row\t" && !(std::cin >> row)){
    std::cout << "Invalid, try again" << std::endl;
  }
  
  pyramid.push_back(1);

  for(unsigned int i = 0; i < row; ++i){
    std::vector<unsigned int> tri;

    unsigned int count = 0;
    unsigned int cur = pyramid[0];
    for(auto it = pyramid.begin(); it != pyramid.end(); ++it){
      if(*it != cur){
        tri.push_back(count);
        tri.push_back(cur);

        cur = *it;
        count = 1;
      } else {
        ++count;
      }
    }
    tri.push_back(count);
    tri.push_back(cur);
    pyramid = tri;
  }

  for(auto it = pyramid.begin(); it != pyramid.end(); ++it){
    std::cout << *it;
  }
  std::cout << std::endl;

  return 0;
}

