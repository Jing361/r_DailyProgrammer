#include<iostream>
#include<fstream>
#include<string>

//TODO: Add input type checking.
int main(int argc, char **argv){
  std::string name;
  std::string age;
  std::string username;
  std::ofstream oFile("record");

  std::cout << "Name: ";
  std::cin >> name;
  std::cout << "Age: ";
  std::cin >> age;
  std::cout << "Username: ";
  std::cin >> username;

  std::cout << "Your name is " << name << " you are " << age << " years old, your username is " << username << "." << std::endl;
  oFile << "Your name is " << name << " you are " << age << " years old, your username is " << username << "." << std::endl;
  oFile.close();

  return 0;
}
