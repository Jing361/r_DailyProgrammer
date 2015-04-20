#ifndef __AUTHENTICATOR_H__
#define __AUTHENTICATOR_H__

#include<iostream>
#include<string>
#include<fstream>
#include<map>

class authenticator{
private:
  std::fstream& handle;
  std::map<std::string, std::string> users;

  void parseUsers();
  void setStdinEcho(bool enable);

public:
  authenticator(std::fstream& inFile);
  bool authenticate(std::string name, std::string pass);
  bool readUser();
};

#endif

