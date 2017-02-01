#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<limits>

#include"authenticator.hh"
#include"hide_std_in.hh"

using namespace std;

int main(){
  fstream testout( "testout", ios::app );

  authenticator auth( "user" );
  string username;
  string password;

  cout << "username:\t";
  while( !( cin >> username ) ){
    cin.clear();
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    cout << "username format error!" << endl;
  }

testout << 'A' << username << 'A' << endl;

  {
    hide_std_in hide;

    cout << "password:\t";
    while( !( cin >> password ) ){
      cin.clear();
      cin.ignore( numeric_limits<streamsize>::max(), '\n' );
      cout << "password format error!" << endl;
    }
  }

testout << 'Z' << password << 'Z' << endl;
  cout << '\n';

  if( !auth.authenticate( username, password ) ){
    cout << "you lose!" << endl;
    return 1;
  } else {
    cout << "you win!" << endl;
    //run normal stuff here.
  }

  return 0;
}

