#include<iostream>
#include<vector>

int main(){
  std::vector<unsigned int>months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  unsigned int month;
  unsigned int day;
  unsigned int total = 0;

  std::cout << "Enter your target date in <month> <day> format." << std::endl;
  std::cin >> month >> day;

  for(unsigned int i = 0; i < month - 1; ++i){
    total += months[i];
  }
  total += day;
  std::cout << total << std::endl;

  return 0;
}

