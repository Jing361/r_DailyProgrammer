#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv){
/*
 *5, 3, 15
 *4, 2, 8
 *6, 2, 12
 */
  string input = "5, 13, 15";
  string delims = ", ";
  vector<string> toks;
  int offset = 0;

  cout << input << endl;
  //Find the tokens from the source string
  while(offset < input.size()){
    string tmp = input.substr(offset, input.find(delims, offset) - offset);
    toks.push_back(tmp);
    offset += tmp.size() + delims.size();
  }

  for(int i = 0; i < toks.size(); ++i){
    for(int j = 0; i < toks.size(); ++j){
      if(j != i){
      }
    }
  }

  return 0;
}

