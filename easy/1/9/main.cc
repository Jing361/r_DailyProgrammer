#include<fstream>
#include<map>
#include<iostream>
#include<string>
#include<regex>
#include<exception>
#include<set>
#include<cctype>

char specialUpper(char c){
  return (char)::toupper(c);
}

class story{
  std::set<std::string> chapters;

public:
  story(std::fstream& file){
    std::string str;

    for(unsigned int i = 0; i < 9; ++i){
      std::getline(file, str);
    }

    do{
      std::string ins;

      std::transform(str.begin()+6, str.end(), ins.begin(), specialUpper);
      chapters.insert(ins);

      std::getline(file, str);
    }while(str != "");
  }

  static bool isRoman(std::string str){
    std::regex exp("[VIXL]*(.)");

    return std::regex_search(str, exp);
  }

  bool isTitle(std::string tok){
    std::transform(tok.begin(), tok.end(), tok.begin(), specialUpper);
    return chapters.count(tok) == 1;
  }

  bool isChapter(std::string tok){
    return false;
  }
};

void printRoman(std::string str){
  std::cout << str << "\t";
  if(story::isRoman(str))
    std::cout << "roman" << std::endl;
  else
    std::cout << "not roman" << std::endl;
}

int main(){
  std::fstream sher("sherlock.txt");
  std::string str;
  std::map<char, unsigned int> counts;
  story lock(sher);

  while(std::getline(sher, str)){
    sher >> str;
    if(!lock.isTitle(str) && !lock.isChapter(str)){
      for_each(str.begin(), str.end(), [&](char c){
        ++counts[toupper(c)];
      });
    } else {
      std::cout << str << std::endl;
    }
  }

  for_each(counts.begin(), counts.end(), [&](std::pair<char, unsigned int> p){
    std::cout << p.first << "\t" << p.second << std::endl;
  });

  sher.close();
  return 0;
}

