#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include"cipher.hh"

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::string;

//string encrypt(string, int);
//string decrypt(string, int);

//TODO: Add input type checking.
int main(int argc, char** argv){
  int crypt;
  bool encrypting;

  if(argc < 3){
    cout << "Not enough arguments." << endl;
    return 1;
  }

  string msg(argv[2]);
  string name(argv[0]);
  string result;
  crypt = atoi(argv[1]);
  cipher cypher(crypt);

  if(name[name.length() - 7] == 'e'){
    encrypting = true;
  } else if(name[name.length() - 7] == 'd'){
    encrypting = false;
  }else {
    cout << "Invalid calling name" << endl;
    return 2;
  }

  for(auto it = msg.begin(); it != msg.end(); ++it){
    if(encrypting){
      result += cypher.encypher(*it);
    }else {
      result += cypher.decypher(*it);
    }
  }

  cout << result << endl;
  return 0;
}

