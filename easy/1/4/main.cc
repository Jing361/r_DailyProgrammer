#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
  unsigned int k;
  unsigned int i = 1;
  std::ifstream listF("list");
  std::vector<std::string> list;

  std::string str;
  while(listF >> str){
    list.push_back(str);
  }

  std::cout << "Enter block size:\t" << std::endl;
  std::cin >> k;

  auto first = list.begin();
  auto last = list.end();
  while(first < last){
    unsigned int inc = k;
    if(k * i >= list.size()){
      inc -= (k * i) - list.size();
    }
    std::reverse(first, first + inc);
    first += inc;
    ++i;
  }

  for(auto it = list.begin(); it != list.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}

