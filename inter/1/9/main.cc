#include<sstream>
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
      std::string ins(str.begin()+6, str.end());

      std::transform(ins.begin(), ins.end(), ins.begin(), specialUpper);
      chapters.insert(ins);

      std::getline(file, str);
    }while(str != "");
  }

  static bool isRoman(std::string str){
    std::regex exp("[VIXL]+\\.");
    return regex_search(str, exp);
  }

  bool isTitle(std::string tok){
    std::transform(tok.begin(), tok.end(), tok.begin(), specialUpper);
    bool ret = false;

    for_each(chapters.begin(), chapters.end(), [&](std::string chapter){
      std::string::size_type pos = tok.find(chapter);
      //result is the last thing in the line
      if(pos != std::string::npos && tok.size() - (pos + chapter.size()) == 0){
        ret = true;
      }
    });
    return ret;
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
  std::map<std::string, unsigned int> counts;
  story lock(sher);

  while(std::getline(sher, str)){
    if(!lock.isTitle(str)){
      std::stringstream ss(str);
      std::string word;
      while(ss >> word){
        std::transform(word.begin(), word.end(), word.begin(), [&](char c){
          return specialUpper(c);
        });
        ++counts[str];
      }
    }
  }

  for_each(counts.begin(), counts.end(), [&](std::pair<std::string, unsigned int> p){
    std::cout << p.first << "\t" << p.second << std::endl;
  });

  sher.close();
  return 0;
}

