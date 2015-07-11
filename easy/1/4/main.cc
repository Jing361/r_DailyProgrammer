#include<iostream>
#include<list>
#include<fstream>
#include<vector>
#include<string>

int main(){
  unsigned int k;
  unsigned int i = 0;
  std::ifstream listF("list");
  std::vector<std::string> list;
  std::vector<std::string> tmp;
  std::vector<std::string> out;

  std::string str;
  while(listF >> str){
    list.push_back(str);
  }

  std::cout << "Enter block size:\t" << std::endl;
  std::cin >> k;

  for(auto it = list.begin(); it != list.end(); ++it){
    tmp.push_back(*it);
    ++i;
    if(i == k){
      while(!tmp.empty()){
        out.push_back(tmp.back());
        tmp.pop_back();
      }
      i = 0;
    }
  }

  for(auto it = out.begin(); it != out.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}

