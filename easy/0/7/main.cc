#include<string>
#include<fstream>
#include<iostream>
#include<map>

using namespace std;

int main( int argc, char** argv ){
  ifstream mFile;
  ifstream file;
  if( argc == 3 ){
    mFile.open( argv[1] );
    file.open( argv[2] );
  } else {
    mFile.open( "morse" );
    file.open( "text" );
  }

  string line;
  map<string, string> words;
  map<string, string> morse;

  words["/"] = " ";
  while( mFile >> line ){
    string letter;
    mFile >> letter;

    words[line] = letter;
    morse[letter] = line;//use to translate text into morse
  }

  string output;

  while( file >> line ){
    output += words[line];
  }

  cout << output << endl;

  return 0;
}

