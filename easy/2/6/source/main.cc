#include<iostream>
#include<string>

using namespace std;

int main( int argc, char** argv ){
  if( argc != 2 ){
    cout << "incorrect number args" << endl;
    return 1;
  }

  string str( argv[1] );
  string actual;
  string extra;

  for( unsigned int i = 1; i < str.size(); ++i ){
    if( str[i] == str[i - 1] ){
      actual += str[i - 1];
      extra += str[i];

      ++i;
    } else {
      actual += str[i - 1];
    }
  }

  cout << actual << endl;
  cout << extra << endl;

  return 0;
}

