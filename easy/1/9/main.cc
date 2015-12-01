#include<fstream>
#include<map>
#include<iostream>
#include<string>
#include<regex>
#include<exception>

bool isRoman(std::string str){
  std::regex exp("[VIX]*");

  return std::regex_search(str, exp);
}

bool isTitle(std::string tok){
  return false;
}

bool isChapter(std::string tok){
  return false;
}

void printRoman(std::string str){
  std::cout << str << "\t";
  if(isRoman(str))
    std::cout << "roman" << std::endl;
  else
    std::cout << "not roman" << std::endl;
}

int main(){
  std::fstream sher("sherlock.txt");
  std::string str;
  std::map<char, unsigned int> counts;

  while(std::getline(sher, str)){
    sher >> str;
    if(!isTitle(str) && !isChapter(str)){
      for_each(str.begin(), str.end(), [&](char c){
        ++counts[c];
      });
    }
  }

  for_each(counts.begin(), counts.end(), [&](std::pair<char, unsigned int> p){
    std::cout << p.first << "\t" << p.second << std::endl;
  });

  sher.close();
  return 0;
}

