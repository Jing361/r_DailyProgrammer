#include<iostream>
#include<tuple>
#include<limits>

#include"hide_std_in.hh"
#include"authenticator.hh"

using namespace std;

int main(){
  authenticator auth( string( "user" ) );
  string user;

  for( auto it = auth.users.begin(); it != auth.users.end(); ++it ){
    cout << get<0>( *it ) << endl;
    cout << get<0>( get<1>( *it ) ) << endl;
    cout << get<1>( get<1>( *it ) ) << endl;
    cout << endl;
  }

  while( true ){
    int opt;
    while( cout << "What would you like to do?\t\n"
                << "1.\tAdd a user\n"
                << "2.\tRemove a user\n"
                << "3.\tFinish\n" &&
           ( !( cin >> opt ) || opt < 1 || opt > 3 ) ){
      cin.clear(); 
      cin.ignore( numeric_limits<streamsize>::max(), '\n' );
      cout << "Invalid input\n";
    }
    string name;
    string pass;

    if( opt < 3 ){
      cout << "Please enter username and password for user:" << endl;
      cout << "username:\t";
      cin >> name;
      cout << "password:\t";
      {
        hide_std_in hide;
        cin >> pass;
      }
    }
    if( opt == 1 ){
      auth.mkUser( name, pass );
    } else if( opt == 2 ){
      auth.rmUser( name, pass );
    } else if( opt == 3 ){
      cout << "Quitting" << endl;
      auth.writeUsers();
      break;
    }
  }
  return 0;
}

