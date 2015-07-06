#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

//Utility functions
void sortstring(std::string& str){
  std::sort(str.begin(), str.end());
}
bool sortvect(std::string str1, std::string str2){
  return str1.size() < str2.size();
}

int main(int argc, char** argv){
  int i;
  std::ifstream scramFile;
  std::ifstream dictFile;
  std::vector<std::string> scram, dict, dctOrg, scrmOrg;
  std::vector<std::string> foundWord, foundScram;
  std::vector<std::string>::iterator itr;

  scramFile.open("scrambled");
  dictFile.open("dictionary");

  for(std::string str; scramFile.good() && getline(scramFile, str); scram.push_back(str))
    scrmOrg.push_back(str);
  for(std::string str; dictFile.good() && getline(dictFile, str); dict.push_back(str))
    dctOrg.push_back(str);

  for_each(scram.begin(), scram.end(), &sortstring);
  for_each(dict.begin(), dict.end(), &sortstring);

  i = 0;
  for(auto it = scram.begin(); it != scram.end(); ++it){
    itr = find(dict.begin(), dict.end(), *it);
    foundWord.push_back(dctOrg.at(itr - dict.begin()));
    foundScram.push_back(scrmOrg[i]);
    ++i;
  }

  std::sort(foundScram.begin(), foundScram.end(), sortvect);
  std::sort(foundWord.begin(), foundWord.end(), sortvect);

  for(unsigned int i = 0; i < foundWord.size() && i < foundScram.size(); ++i){
    std::cout << "Scrambled word:\t" << foundScram[i] << "\tbecomes:\t" << foundWord[i] << std::endl;
  }

  scramFile.close();
  dictFile.close();

  return 0;
}

