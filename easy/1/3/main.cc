#include<limits>
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main(int argc, char** argv){
  if(argc != 1 && argc != 3){
    cout << "Invalid number of argumets" << endl;
    return 1;
  }

  unsigned int month = 0;
  unsigned int day = 0;
  if(argc == 3){
    stringstream ss;
    ss << argv[1];
    ss >> month;
    ss.clear();
    ss << argv[2];
    ss >> day;
  }

  vector<unsigned int>months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  unsigned int total = 0;

  if(month == 0 || day == 0){
    while( cout << "Enter your target date in <month> <day> format." << endl
        && !( cin >> month >> day )
        && ( month == 0 || day == 0 ) ){
      cin.clear();
      cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    }
  }

  for(unsigned int i = 0; i < month - 1; ++i){
    total += months[i];
  }

  total += day;
  cout << total << endl;

  return 0;
}

