#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::string;

//TODO: Add input type checking.
int main(int argc, char** argv){
  int crypt;
  bool encrypting;
  ofstream oFile;

  if(argc < 3){
    cout << "1" << endl;
    return 1;
  }

  string msg(argv[2]);
  string name(argv[0]);
  string result;
  crypt = atoi(argv[1]);
  oFile.open("message");

  if(name == "encrypt"){
    encrypting = true;
  } else if(name == "decrypt"){
    encrypting = false;
  }

  for(std::string::iterator it = msg.begin(); it != msg.end(); ++it){
    //Assuming *it returns a char.
    //  Not 100% confident this is true.
    int shift;
    if(encrypting){
      shift = (int)*it + crypt;
    } else {
      shift = (int)*it - crypt;
    }

    if(*it >= 65 && *it <= 90){
      shift -= 65;
      shift %= 90;
      shift += 65;
    } else if(*it >= 97 && *it <= 122){
      shift -= 97;
      shift %= 26;
      shift += 97;
    }

    result += (char)shift;
  }

  cout << result << endl;

  oFile.close();
  return 0;
}

