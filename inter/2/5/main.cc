#include<iostream>
#include<string>
#include<sstream>
#include<bitset>

int main(){
  int num;
  std::cin >> num;
  std::bitset<8> bs(num);

  std::cout << bs << std::endl;

  return 0;
}

