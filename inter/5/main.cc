#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>

int main(){
  std::ifstream dictFile("dictionary", std::ifstream::in);
  std::vector<std::string> words;
  std::vector<std::string> sorted;
  char cword[128];

  while(!dictFile.eof()){
    dictFile.getline(cword, 127);
    words.push_back(std::string(cword));
  }

  sorted = words;

  for(auto it = sorted.begin(); it != sorted.end(); ++it){
    std::sort((*it).begin(), (*it).end());
  }

  for(unsigned int i = 0; i < sorted.size(); ++i){
    std::string tmp(sorted[i]);
    std::cout << words[i] << std::endl;
    for(unsigned int j = i + 1; j < sorted.size(); ++j){
      if(tmp == sorted[j]){
        std::cout << "\t" << words[j] << std::endl;
      }
    }
  }

  dictFile.close();
  return 0;
}

