#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<sstream>
#include<exception>

using namespace std;

class formatFailureException : public exception{
private:
  string mMsg;

public:
  formatFailureException(string msg):
    mMsg(msg){
  }

  const char* what() const noexcept{
    return mMsg.c_str();
  }
};

int main(int argc, char** argv){
  if(argc != 2){
    string msg("Incorrect number of parameters!");
    if(argc == 1){
      msg += " No file specified!";
    }
    throw formatFailureException(msg);
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
    if(tok.size() != 1 && tok[0] != ':'){
      throw formatFailureException("File: " + string(argv[1]) + " is incorrectly formatted.");
    }
    ss >> tok;
    ppl.insert(tok);
  }

  for(auto it:ppl)
    cout << it << endl;

  return 0;
}

