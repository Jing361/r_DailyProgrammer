#include<iostream>
#include<vector>

int main(){
  unsigned int row;
  unsigned int idx;
  std::vector<unsigned int> triangle;

  do{
    std::cout << "Input coordinates: ";
    std::cin >> row;
    std::cin >> idx;
  }while(idx > row);

  triangle.push_back(1);
  triangle.push_back(1);

  for(unsigned int i = 2; i < row; ++i){
    std::vector<unsigned int> tri;
    auto first = triangle.begin();
    auto second = ++triangle.begin();

    tri.push_back(1);
    for(auto it = triangle.begin(); it != triangle.end(); ++it){
      tri.push_back((*first++) + (*second++));
    }

    triangle = tri;
  }

  std::cout << triangle[idx - 1] << std::endl;

  return 0;
}

