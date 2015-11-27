#include<fstream>
#include<map>
#include<iostream>
#include<string>
#include<regex>
#include<exception>

bool isRoman(std::string str){
  std::regex exp("[VIX]*");

  return std::regex_match(str, exp);
}

int main(){
//  std::fstream sher("sherlock.txt");
  std::string str;
  std::map<char, unsigned int> counts;

/*  while(std::getline(sher, str)){
  }*/
  try{
  if(isRoman("aoeu")){
    std::cout << "roman" << std::endl;
  } else {
    std::cout << "not roman" << std::endl;
  }
  if(isRoman("XIV")){
     std::cout << "roman" << std::endl;
  } else {
    std::cout << "not roman" << std::endl;
  }
  if(isRoman("VIX")){
     std::cout << "roman" << std::endl;
  } else {
    std::cout << "not roman" << std::endl;
  }
  if(isRoman("VV")){
     std::cout << "roman" << std::endl;
  } else {
    std::cout << "not roman" << std::endl;
  }
  if(isRoman("V")){
     std::cout << "roman" << std::endl;
  } else {
    std::cout << "not roman" << std::endl;
  }
  } catch(const std::regex_error& e){
    if(e.code() == std::regex_constants::error_brack){
      std::cout << "yes" << std::endl;
    }
    std::cout << e.what() << std::endl;
  }


  //sher.close();
  return 0;
}

