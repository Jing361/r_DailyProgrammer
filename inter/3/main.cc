#include<iostream>
#include<queue>
#include<array>
#include"cipher.hh"

using std::cout;
using std::endl;
using std::string;

//TODO: Establish decryption.
int main(int argc, char** argv){
  if(argc < 3){
    cout << "Not enough arguments." << endl;
    return 1;
  }

  cipher cypher(argv[1]);
  string msg(argv[2]);
  string result;

  for(string::iterator it = msg.begin(); it != msg.end(); ++it){
    result += cypher.encypher(*it);
  }

  cout << result << endl;
  return 0;
}

