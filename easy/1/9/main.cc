#include<fstream>
#include<map>
#include<iostream>
#include<string>
#include<regex>
#include<exception>

bool isRoman(std::string str){
  //std::regex exp("[VIX]*");
  std::regex exp("[VIX]*");

  return std::regex_match(str, exp);
}

void printRoman(std::string str){
  std::cout << str << "\t";
  if(isRoman(str))
    std::cout << "roman" << std::endl;
  else
    std::cout << "not roman" << std::endl;
}

int main(){
//  std::fstream sher("sherlock.txt");
  std::string str;
  std::map<char, unsigned int> counts;

/*  while(std::getline(sher, str)){
  }*/
  try{
  printRoman("aoeu");
  printRoman("XIV");
  printRoman("VIX");
  printRoman("VV");
  printRoman("V");
  printRoman("9");
  } catch(const std::regex_error& e){
    if(e.code() == std::regex_constants::error_brack){
      std::cout << "yes" << std::endl;
    }
    std::cout << e.what() << std::endl;
  }

  //sher.close();
  return 0;
}

