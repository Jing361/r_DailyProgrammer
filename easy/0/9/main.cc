#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(){
  std::string text;
  std::vector<char> v;

  std::cout << "provide some text to sort" << std::endl;
  std::cin >> text;

  std::sort(text.begin(), text.end());

  std::cout << text << std::endl;

  return 0;
}

