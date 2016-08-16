#include<sstream>
#include<fstream>
#include<map>
#include<iostream>
#include<string>
#include<regex>
#include<exception>
#include<set>
#include<cctype>
#include<locale>
#include<algorithm> 
#include<functional> 

static inline std::string &ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::ispunct))));
  return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::ispunct))).base(), s.end());
  return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
  return ltrim(rtrim(s));
}

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

int main(int argc, char** argv){
  std::string str;
  if(argc == 2){
    str = argv[1];
  } else {
    str = "data/sherlock.txt";
  }

  std::fstream sher(str);
  std::map<std::string, unsigned int> counts;
  std::multimap<std::string, unsigned int> pages;
  story lock(sher);
  unsigned long page = 0;
  unsigned long line = 0;

  while(std::getline(sher, str)){
    if(++line > 40){
      ++page;
    }
    if(!lock.isTitle(str)){
      std::stringstream ss(str);
      std::string word;
      while(ss >> word){
        trim(word);
        std::transform(word.begin(), word.end(), word.begin(), [&](char c){
          return specialUpper(c);
        });
        pages.insert(std::pair<std::string, unsigned int>(word, page));
        ++counts[word];
      }
    }
  }

  std::string lineWord;
  for(auto it = pages.begin(); it != pages.end(); ++it){
    if(counts[(*it).first] < 15){
      if(lineWord != (*it).first){
        lineWord = (*it).first;
        std::cout << std::endl << (*it).first << '\t';
      }

      std::cout << (*it).second << ", ";
    }
  }

  sher.close();
  return 0;
}

