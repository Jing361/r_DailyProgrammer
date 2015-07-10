#include<iostream>
#include<string>
#include<sstream>

int main(int argc, char** argv){
  std::string input;
  std::string number;
  unsigned int test;
  bool good;

  if(argc > 1){
    std::stringstream ss;

    input = argv[1];
    ss << input;
    ss >> test;
  }

  if(input == "" || test == 0){
    do{
      std::stringstream ss;

      std::cout << "Input an integer\t" << std::flush;
      std::cin >> input;
      ss << input;
      good = (ss >> test);
    }while(!good && (std::cout << "Try again!  We need an integer." << std::endl));
  }

  std::stringstream ss;
  unsigned int siz;

  ss << test;
  ss >> input;
  siz = input.length() + 1;

  for(auto it = input.begin(); it != input.end(); ++it){
    --siz;
    if(*it == '0'){
      continue;
    } else if((siz + 1) % 3 == 0){//handle things like seventy
      std::string num;
      switch(*it){
      case '1':
        num = "one ";
      break;
      case '2':
        num = "twenty ";
      break;
      case '3':
        num = "thirty ";
      break;
      case '4':
        num = "forty ";
      break;
      case '5':
        num = "fifty ";
      break;
      case '6':
        num = "sixty ";
      break;
      case '7':
        num = "seventy ";
      break;
      case '8':
        num = "eighty ";
      break;
      case '9':
        num = "ninety ";
      break;
      }
      number += num;
    } else {
      std::string num;
      switch(*it){
      case '1':
        num = "one ";
      break;
      case '2':
        num = "two ";
      break;
      case '3':
        num = "three ";
      break;
      case '4':
        num = "four ";
      break;
      case '5':
        num = "five ";
      break;
      case '6':
        num = "six ";
      break;
      case '7':
        num = "seven ";
      break;
      case '8':
        num = "eight ";
      break;
      case '9':
        num = "nine ";
      break;
      };

      number += num;

    }

    std::string order;//of magnitude
    switch(siz){
    case 1:
      order = "";
    break;
    case 2:
      order = "";
    break;
    case 3:
      order = "hundred ";
    break;
    case 4:
      order = "thousand ";
    break;
    case 5:
      order = "thousand ";
    break;
    case 6:
      order = "hundred thousand ";
    break;
    case 7:
      order = "million ";
    break;
    };

    number += order;

  }

  std::cout << number << std::endl;

  return 0;
}

