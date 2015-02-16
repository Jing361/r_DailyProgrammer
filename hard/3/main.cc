#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::sort;

void sortstring(string& str){
  sort(str.begin(), str.end());
}

int main(int argc, char** argv){
  int i;
  ifstream scramFile;
  ifstream dictFile;
  vector<string> scram, dict, dctOrg, scrmOrg;
  vector<string> foundWord, foundScram;
  vector<string>::iterator itr;

  scramFile.open("scrambled");
  dictFile.open("dictionary");

  for(string str; scramFile.good() && getline(scramFile, str); scram.push_back(str))
    scrmOrg.push_back(str);
  for(string str; dictFile.good() && getline(dictFile, str); dict.push_back(str))
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

  for(int i = 0; i < foundWord.size() && i < foundScram.size(); ++i){
    cout << "Scrambled word:\t" << foundScram[i] << "\tbecomes:\t" << foundWord[i] << endl;
  }

  scramFile.close();
  dictFile.close();

  return 0;
}

