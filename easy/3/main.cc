#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

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

  if(name[name.size() - 7] == 'e'){
    encrypting = true;
  } else if(name[name.size() - 7] == 'd'){
    encrypting = false;
  }

  for(std::string::iterator it = msg.begin(); it != msg.end(); ++it){
    //Assuming *it returns a char.
    //  Not 100% confident this is true.
    int val;
    int lowBound;
    int upBound;

    if(encrypting){
      val = (int)*it + crypt;
    } else {
      val = (int)*it - crypt;
    }

    if(*it >= 65 && *it <= 90){
      lowBound = 65;
      upBound = 90;
    } else if(*it >= 97 && *it <= 122){
      lowBound = 97;
      upBound = 122;
    } else {
      result += *it;
      continue;
    }

    val -= lowBound;
    if(val < 0){
      val = 26 + val;
    } else {
      val %= 26;
    }
    val += lowBound;

    result += (char)val;
  }
  cout << result << endl;
  return 0;
}

