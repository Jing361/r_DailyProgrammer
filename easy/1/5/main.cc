#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char** argv){
  if(argc != 2){
    return 1;
  }
  fstream fs(argv[1]);
  string line;

  int max = 0;
  while(getline(fs, line)){
    if(line.size() > max){
      max = line.size();
    }
  }

  fs.close();
  fs.open(argv[1]);

  while(getline(fs, line)){
    for(int i = 0; i < max - line.size(); ++i){
      cout << ' ';
    }
    cout << line << endl;
  }
  cout << endl;

  return 0;
}

