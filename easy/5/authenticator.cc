#include"authenticator.hh"
#include<termios.h>
#include<unistd.h>
#include<functional>
#include<exception>
#include<sstream>

authenticator::authenticator(std::string file):
  fileName(file){
  parseUsers();
}

bool authenticator::authenticate(std::string name, std::string pass){
  std::hash<std::string> str_hash;
  return users[name] == str_hash(pass);
}

void authenticator::mkUser(std::string name, std::string pass){
  std::hash<std::string> str_hash;
  users[name] = str_hash(pass);
}

void authenticator::rmUser(std::string name, std::string pass){
  if(authenticate(name, pass)){
    users.erase(name);
  }
}

bool authenticator::readUser(){
  std::string username;
  std::string password;

  std::cout << "username:\t";
  std::cin >> username;
  if(std::cin.fail()){
    std::cerr << "format error!" << std::endl;
    return false;
  }

  std::cout << "password:\t";
  setStdinEcho(false);
  std::cin >> password;
  setStdinEcho(true);
  if(std::cin.fail()){
    std::cerr << "format error!" << std::endl;
    return false;
  }
  std::cout << std::endl;

  return authenticate(username, password);
}

void authenticator::writeUsers(){
  std::fstream handle(fileName.c_str(), std::fstream::out | std::fstream::trunc);
  for(auto it = users.begin(); it != users.end(); ++it){
    handle << std::get<0>(*it) << std::endl;
    handle << std::get<1>(*it) << std::endl;
  }
  handle.close();
}

void authenticator::parseUsers(){
  std::fstream handle(fileName.c_str(), std::fstream::in);
  while(!handle.eof()){
    std::stringstream stream;
    size_t hash;
    
    char cname[256];
    char cpass[256];
    handle.getline(cname, 255);
    handle.getline(cpass, 255);
    stream << std::string(cpass);
    stream >> hash;
    users[std::string(cname)] = hash;
    users.erase(std::string(""));
  }
  handle.close();
}

void authenticator::setStdinEcho(bool enable){
  struct termios tty;
  tcgetattr(STDIN_FILENO, &tty);
  if(!enable){
    tty.c_lflag &= ~ECHO;
  } else {
    tty.c_lflag |= ECHO;
  }
  (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

