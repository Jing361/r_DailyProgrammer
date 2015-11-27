#include<algorithm>
#include<string>
#include<iostream>

int main(int argc, char** argv){
  std::string first(argv[1]);
  std::string second(argv[2]);
  std::string result;

  for_each(first.begin(), first.end(), [&](char fc){
    auto it = find_if(second.begin(), second.end(), [&](char sc){
      return sc == fc;
    });
    if(auto != second.end()){
      result += *it;
    }
  });

  std::cout << result << std::endl;
  return 0;
}

