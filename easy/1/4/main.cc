#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  unsigned int k;
  unsigned int i = 1;
  ifstream listF( "list" );
  vector<string> list;

  string str;
  while( listF >> str ){
    list.push_back( str );
  }

  cout << "Enter block size:\t" << endl;
  cin >> k;

  auto first = list.begin();
  auto last = list.end();

  while( first < last ){
    unsigned int inc = k;

    if( k * i >= list.size() ){
      inc -= ( k * i ) - list.size();
    }

    reverse( first, first + inc );
    first += inc;
    ++i;
  }

  for( auto it = list.begin(); it != list.end(); ++it ){
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}

