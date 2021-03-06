#ifndef __AUTHENTICATOR_H__
#define __AUTHENTICATOR_H__

#include<string>
#include<map>
#include<tuple>

class authenticator{
private:
  std::string fileName;
  std::map<std::string, std::pair<std::string, std::size_t> > users;

  void
  parseUsers();

  std::string
  genSalt();

public:
  authenticator( std::string file );

  bool
  authenticate( std::string name, std::string pass );

  void
  mkUser( std::string name, std::string pass );

  void
  rmUser( std::string name, std::string pass );

  void
  writeUsers();
};

#endif

