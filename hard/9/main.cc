#include<iostream>
#include<vector>

int main(){
  std::vector<unsigned int> pyramid;
  unsigned int row;

  while(std::cout << "Input row\t" && !(std::cin >> row)){
    std::cout << "Invalid, try again" << std::endl;
  }
  
  pyramid.push_back(1);

  for(unsigned int i = 2; i < row; ++i){
    std::vector<unsigned int> tri;
    auto first = pyramid.begin();
    auto second = ++pyramid.begin();

    tri.push_back(1);
    for(auto it = pyramid.begin(); it != pyramid.end(); ++it){
      tri.push_back((*first++) + (*second++));
    }

    pyramid = tri;

    for(auto it = pyramid.begin(); it != pyramid.end(); ++it){
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

