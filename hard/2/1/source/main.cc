#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<sstream>

using namespace std;

int main(int argc, char** argv){
  if(argc != 2){
    return 1;
  }

  set<string> ppl;
  fstream fs(argv[1]);

  string line;
  while(getline(fs, line)){
    stringstream ss(line);
    string tok;

    ss >> tok;
    ppl.insert(tok);
    ss >> tok;
    if(tok != ':'){
      return 1;
    }
    ss >> tok;
    ppl.insert(tok);
  }

  for(auto it:ppl)
    cout << it << endl;

  return 0;
}

