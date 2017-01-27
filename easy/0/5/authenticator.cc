#include<functional>
#include<exception>
#include<sstream>
#include<random>

#include"authenticator.hh"

using namespace std;

authenticator::authenticator( string file ):
  fileName( file ){
  parseUsers();
}

bool authenticator::authenticate( string name, string pass ){
  hash<string> str_hash;
  pair<string, size_t> user = users[name];
  string salt = get<0>( user );
  size_t hash = get<1>( user );

  return hash == str_hash( salt + pass );
}

void authenticator::mkUser( string name, string pass ){
  hash<string> str_hash;
  string salt = genSalt();

  users[name] = pair<string, size_t>( salt, str_hash( salt + pass ) );
}

void authenticator::rmUser( string name, string pass ){
  if( authenticate( name, pass ) ){
    users.erase( name );
  }
}

void authenticator::writeUsers(){
  fstream handle( fileName.c_str(), fstream::out | fstream::trunc );

  for( auto it = users.begin(); it != users.end(); ++it ){
    handle << get<0>( *it ) << endl;
    handle << get<0>( get<1>( *it ) ) << endl;
    handle << get<1>( get<1>( *it ) ) << endl;
  }
}

void authenticator::parseUsers(){
  fstream handle( fileName.c_str(), fstream::in );
  string name;
  string salt;
  size_t hash;

  while( handle >> name && handle >> salt && handle >> hash ){
    users[name] = pair<string, size_t>( salt, hash );
  }
}

string authenticator::genSalt(){
  random_device rd;
  mt19937 rate( rd() );
  uniform_int_distribution<> gene( 33, 126 );
  string salt;

  for( unsigned int i = 0; i < 15; ++i ){
    salt += ( char )gene( rate );
  }
  return salt;
}


