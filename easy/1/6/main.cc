#include<set>
#include<string>
#include<iostream>

using namespace std;

int main( int argc, char** argv ){
  string first( argv[1] );
  string second( argv[2] );
  string result;
  set<char> bad( second.begin(), second.end() );

  for( auto fc : first ){
    if( bad.count( fc ) == 0 ){
      result += fc;
    }
  }

  cout << result << endl;

  return 0;
}

