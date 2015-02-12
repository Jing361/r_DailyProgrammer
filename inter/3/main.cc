#include<iostream>
#include<queue>
#include<array>
#include"cipher.hh"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv){
  if(argc < 3){
    cout << "Not enough arguments." << endl;
    return 1;
  }

  cipher cypher(argv[1]);
  string msg(argv[2]);
  string result;
  string left;
  string right;

cout << cypher << endl;
for(int i = 0; i < cypher.length(); ++i){
  if(i < cypher.length()/2)
    left += cypher[i];
  else
    right += cypher[i];
}
cout << left << endl;
cout << right << endl;

  for(string::iterator it = msg.begin(); it != msg.end(); ++it){
    result += cypher.encypher(*it);
  }

  cout << result << endl;
  return 0;
}

