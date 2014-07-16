#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>
using std::cout;
using std::cin;
using std::endl;

int eval(int high, int low);

int main(int argc, char** argv){
  char resp = 'n';
  int high = 100;
  int low = 1;
  int guess;

  if(argc == 2){
    char *endptr;
    long val;
    errno = 0;

    val = strtol(argv[1], &endptr, 10);
    if((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0)) {
      cout << "Error parsing number parameter" << endl;
    } else if(endptr == argv[1]) {
      cout << "No digits found, ignoring program parameter";
    } else {
      // If we got here, strtol() successfully parsed a number.
      high = val;
    }
  }

  cout << "Choose a number between 1 and " << high << " inclusively." << endl;
  cout << "Press enter to continue.";
  cin.ignore();

  while(resp != 'y' && resp != 'Y'){
    guess = eval(high, low);
    cout << "Is " << guess << " your number?" << endl;
    cout << "(Y for correct number H for too high and L for too low)" << endl;
    cin >> resp;

    if(resp == 'h' || resp == 'H'){
      high = guess;
    } else if(resp == 'l' || resp == 'L'){
      low = guess;
    }
  }
  return 0;
}

int eval(int high, int low){
  return ((high - low)/2) + low;
}

