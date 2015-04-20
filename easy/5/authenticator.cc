#include"authenticator.hh"
#include<termios.h>
#include<unistd.h>

authenticator::authenticator(std::fstream& inFile):
  handle(inFile){
  parseUsers();
}

bool authenticator::authenticate(std::string name, std::string pass){
  return users[name] == pass;
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

void authenticator::parseUsers(){
  while(!handle.eof()){
    char cname[256];
    char cpass[256];
    handle.getline(cname, 255);
    handle.getline(cpass, 255);
    users[std::string(cname)] = std::string(cpass);
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

