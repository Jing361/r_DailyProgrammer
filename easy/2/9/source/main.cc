#include<string>
#include<iostream>

using namespace std;

int main( int argc, char** argv ){
  if( argc != 2 ){
    cout << "wrong number of args" << endl;
    return 1;
  }

  string str( argv[1] );
  unsigned int start = 0;
  unsigned int end = str.size() - 1;

  while( start < end && str[start] == str[end] ){
    ++start;
    --end;
  }

  if( ( start - end ) <= 1 ){
    cout << "yay!" << endl;
  } else {
    cout << "boo!" << endl;
  }

  cout << start << endl;
  cout << end << endl;

  return 0;
}

