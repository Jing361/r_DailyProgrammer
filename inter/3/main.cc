#include<iostream>
#include<queue>
#include<array>

using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::array;

int main(int argc, char** argv){
  int i;
  int crypt;
  queue<char> translate;
  array<char, 13> leftHalf;
  array<char, 13> rightHalf;

  if(argc < 3){
    cout << "Not enough arguments." << endl;
    return 1;
  }

  string msg(argv[2]);
  string name(argv[0]);
  string result;
  crypt = atoi(argv[1]);

  for(int i = 0; i < 26; ++i){
    translate.push((char)(i + 65));
  }
  for(int i = 0; i < crypt; ++i){
    translate.push(translate.front());
    translate.pop();
  }
  for(int i = 0; i < 26; ++i){
    if(i < 13){
      leftHalf[i] = translate.front();
    }else if(i > 13){
      rightHalf[i + 13] = translate.front();
    }
    translate.pop();
  }

  for(string::iterator it = msg.begin(); it != msg.end(); ++it){
    for(auto ait = leftHalf.begin(); ait != leftHalf.end(); ++ait){
      if(*ait == *it){
        break;
      }
      ++i;
    }
  }

  cout << result << endl;
  return 0;
}

