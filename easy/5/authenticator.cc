#include"authenticator.hh"
#include<termios.h>
#include<unistd.h>
#include<functional>
#include<exception>

authenticator::authenticator(std::fstream& inFile):
  handle(inFile){
  parseUsers();
}

bool authenticator::authenticate(std::string name, std::string pass){
  std::hash<std::string> str_hash;
  return users[name] == str_hash(pass);
}

void mkUser(std::string name, std::string pass){
  std::hash<std::string> str_hash;
  users[name] = str_hash(pass);
}

void rmUser(std::string name, std::string pass){
  if(authenticate(name, pass)){
    users.erase(name);
  }
}

std::tuple<std::string, std::size_t> authenticator::readUser(){
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

  return std::tuple<std::string, std::size_t>(username, password);
}

void authenticator::parseUsers(){
  while(!handle.eof()){
    char cname[256];
    char cpass[256];
    handle.getline(cname, 255);
    handle.getline(cpass, 255);
    try{
      users[std::string(cname)] = std::stoi(std::string(cpass));
    } catch(std::exception& e) {
      users.erase(std::string(""));
    }
  }
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

