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

  dictFile.close();
  return 0;
}

