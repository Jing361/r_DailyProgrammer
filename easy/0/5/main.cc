#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#include"authenticator.hh"
#include"hide_std_in.hh"

using namespace std;

int main(){
  authenticator auth(string("user"));
  string username;
  string password;

  cout << "username:\t";
  while( !( cin >> username ) ){
    cout << "format error!" << endl;
  }

  {
    cout << "password:\t";
    hide_std_in hide;
    while( cin >> password ){
      cerr << "format error!" << endl;
    }
  }

  cout << endl;

  if( !auth.authenticate( username, password ) ){
    cout << "you lose!" << endl;
    return 1;
  } else {
    cout << "you win!" << endl;
    //run normal stuff here.
  }

  return 0;
}

