#include<iostream>
#include<vector>
#include<sstream>

int main(int argc, char** argv){
  if(argc != 1 && argc != 3){
    std::cout << "Invalid number of argumets" << std::endl;
    return 1;
  }

  unsigned int month = 0;
  unsigned int day = 0;
  if(argc == 3){
    std::stringstream ss;
    ss << argv[1];
    ss >> month;
    ss.clear();
    ss << argv[2];
    ss >> day;
  }
  std::vector<unsigned int>months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  unsigned int total = 0;

  if(month == 0 || day == 0){
    std::cout << "Enter your target date in <month> <day> format." << std::endl;
    std::cin >> month >> day;
  }

  for(unsigned int i = 0; i < month - 1; ++i){
    total += months[i];
  }
  total += day;
  std::cout << total << std::endl;

  return 0;
}

