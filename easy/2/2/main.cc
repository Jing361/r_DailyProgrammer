#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>

int main(){
  std::vector<std::string> master;
  std::vector<std::string> empty;
  std::vector<std::vector<std::string>> lists;
  std::string line;

  while(std::getline(std::cin, line)){
    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> list;

    while(ss >>word){
      list.push_back(word);
    }
    lists.push_back(list);
  }

  for(auto it:lists){
    std::set_union(master.begin(), master.end(), it.begin(), it.end(), std::back_inserter(empty));
    master.assign(empty.begin(), empty.end());
    empty.clear();
  }
  for(auto it:master){
    std::cout << it << '\t';
  }
  std::cout << std::endl;

  return 0;
}

