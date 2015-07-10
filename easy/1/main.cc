#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

//TODO: Add input type checking.
int main(int argc, char **argv){
    char name[255];
    char age[5];
    char username[255];
    ofstream oFile;
    oFile.open("record");

    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Username: ";
    cin >> username;

    cout << "Your name is " << name << " you are " << age << " years old, your username is " << username << "." << endl;
    oFile << "Your name is " << name << " you are " << age << " years old, your username is " << username << "." << endl;
    oFile.close();

    return 0;
}
