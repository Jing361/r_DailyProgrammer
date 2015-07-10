#include<iostream>
#include<fstream>

//TODO: Add input type checking.
int main(int argc, char **argv){
    char name[255];
    char age[5];
    char username[255];
    std::ofstream oFile;
    oFile.open("record");

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
