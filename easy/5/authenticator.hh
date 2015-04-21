#ifndef __AUTHENTICATOR_H__
#define __AUTHENTICATOR_H__

#include<iostream>
#include<string>
#include<fstream>
#include<map>

class authenticator{
private:
  std::string fileName;

  void parseUsers();
  std::string genSalt();

public:
  std::map<std::string, std::size_t> users;

  authenticator(std::string file);
  bool authenticate(std::string name, std::string pass);
  void mkUser(std::string name, std::string pass);
  void rmUser(std::string name, std::string pass);
  bool readUser();
  void writeUsers();

  static void setStdinEcho(bool enable);
};

#endif
