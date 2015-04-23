#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>

int main(){
  std::ifstream dictFile("dictionary", std::ifstream::in);
  std::vector<std::string> words;
  std::vector<std::string> sorted;
  std::map<std::string, std::vector<std::string> > anagrams;
  char cword[128];

  std::cout << "Processing dictionary...\n" << std::flush;

  while(!dictFile.eof()){
    dictFile.getline(cword, 127);
    words.push_back(std::string(cword));
  }

  std::cout << "\tDictionary read.\n" << std::flush;

  sorted = words;

  for(auto it = sorted.begin(); it != sorted.end(); ++it){
    std::sort((*it).begin(), (*it).end());
  }

  std::cout << "\tWords processed.\n" << std::flush;

  for(unsigned int i = 0; i < sorted.size(); ++i){
    std::string tmp(sorted[i]);
    for(unsigned int j = 0; j < sorted.size(); ++j){
      if(tmp == sorted[j]){
        anagrams[words[i]].push_back(words[j]);
      }
    }
  }

  std::cout << "Dictionary processed!\n" << std::flush;

  while(true){
    std::string input;
    std::cout << "I'd like to see anagrams for ";
    std::cin >> input;
    for(auto it = anagrams[input].begin(); it != anagrams[input].end(); ++it){
      std::cout << "\t" << *it << std::endl;
    }
  }

  dictFile.close();
  return 0;
}
