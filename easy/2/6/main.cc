#include<iostream>
#include<string>

int main(){
  std::string source;
  std::string first;
  std::string second;
  unsigned int i = 0;

  std::cin >> source;

  while(i < source.size()){
    if(source[i] == source[i + 1]){
      first += source[i];
      second += source[i];
      i += 2;
    } else {
      first += source[i];
      i += 1;
    }
  }

  std::cout << first << std::endl;
  std::cout << second << std::endl;

  return 0;
}

