#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<sstream>

//TODO: Add input type checking.
int main(){
  std::string name;
  unsigned int age;
  std::string username;
  std::ofstream oFile("record");

  std::cout << "Name: ";
  std::cin >> name;
  while(std::cout << "Age: " && !(std::cin >> age)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Not a number" << std::endl;
  }
  std::cout << "Username: ";
  std::cin >> username;

  std::stringstream ss;
  std::string sAge;
  ss << age;
  ss >> sAge;
  
  std::string output = "Your name is " + name + " you are " + sAge + " years old, your username is " + username + ".\n";

  std::cout << output;
  oFile << output;

  oFile.close();
  return 0;
}
