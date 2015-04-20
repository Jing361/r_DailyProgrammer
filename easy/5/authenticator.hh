#ifndef __AUTHENTICATOR_H__
#define __AUTHENTICATOR_H__

#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<tuple>

class authenticator{
private:
  std::fstream& handle;

  void parseUsers();
  void setStdinEcho(bool enable);

public:
  std::map<std::string, std::size_t> users;

  authenticator(std::fstream& inFile);
  bool authenticate(std::string name, std::string pass);
  void mkUser(std::string name, std::string pass);
  void rmUser(std::string name, std::string pass);
  std::tuple<std::string, std::size_t> readUser();
  void writeUsers();
};

#endif

