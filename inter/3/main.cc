#include<iostream>
#include<queue>
#include<array>

using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::array;

int main(int argc, char** argv){
  int j;
  int crypt;
  bool foundVal;
  queue<char> translate;
  array<char, 64> leftHalf;
  array<char, 64> rightHalf;

  if(argc < 3){
    cout << "Not enough arguments." << endl;
    return 1;
  }

  string msg(argv[2]);
  string name(argv[0]);
  string result;
  crypt = atoi(argv[1]);

  for(int i = 0; i < 127; ++i){
    translate.push((char)(i));
  }
  for(int i = 0; i < crypt; ++i){
    translate.push(translate.front());
    translate.pop();
  }

  for(int i = 0; i < 127; ++i){
    if(i < 63){
      leftHalf[i] = translate.front();
    }else if(i >= 63){
      rightHalf[i - 63] = translate.front();
    }
    translate.pop();
  }

  j = 0;
  foundVal = false;
  for(string::iterator it = msg.begin(); it != msg.end(); ++it){
    for(auto ait = leftHalf.begin(); ait != leftHalf.end(); ++ait){
      if(*ait == *it){
        foundVal = true;
        break;
      }
      ++j;
    }
    if(foundVal){
      result += leftHalf[j];
    } else {
      j = 0;
      for(auto ait = rightHalf.begin(); ait != rightHalf.end(); ++ait){
        if(*ait == *it){
          break;
        }
        ++j;
      }
      result += rightHalf[j];
    }
  }

  cout << result << endl;
  return 0;
}

