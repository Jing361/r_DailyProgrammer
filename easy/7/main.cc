#include<string>
#include<fstream>
#include<iostream>
#include<map>

int main(){
  std::ifstream mFile("morse");
  std::ifstream file("text");
  std::string line;
  std::string output;
  std::map<std::string, std::string> words;
  std::map<std::string, std::string> morse;

  words[std::string("/")] = std::string(" ");
  while(mFile >> line){
    std::string letter;
    mFile >> letter;
    words[line] = letter;
    morse[letter] = line;//use to translate text into morse
  }

  while(file >> line){
    output += words[line];
  }

  std::cout << output << std::endl;

  file.close();
  return 0;
}

