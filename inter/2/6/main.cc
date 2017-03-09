#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main( int argc, char** argv ){
  if( argc != 2 ){
    cout << "incorrect number args" << endl;
    return 1;
  }

  fstream data( argv[1] );
  string line;

  while( getline( data, line ) ){
    if( line.size() == 0 ){
      continue;
    }
    string name;
    string age;
    string pay;
    auto nameEnd = line.find( ',' );
    auto ageEnd = line.rfind( ',' );

    cout << line << endl;

    name = line.substr( 0, nameEnd );
    age = line.substr( nameEnd + 2, ageEnd - nameEnd - 2 );
    pay = line.substr( ageEnd + 2 );

    cout << name << endl;
    cout << age << endl;
    cout << pay << endl;
    cout << endl;
  }
  
  return 0;
}

