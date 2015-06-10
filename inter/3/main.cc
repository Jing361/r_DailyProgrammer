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
    cout << "Use as " << argv[0] << " [key] [message]" << std::endl;
    cout << "[key] is interpretted as a number, and [message] as text" << std::endl;
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

