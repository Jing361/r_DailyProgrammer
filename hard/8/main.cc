#include<iostream>

int main(){
  unsigned int row;
  unsigned int idx;
  do{
    std::cout << "Input coordinates: ";
    std::cin >> row;
    std::cin >> idx;
  }while(idx > row);

  return 0;
}

