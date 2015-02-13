#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

int main(int argc, char** argv){
  int max = 100;
  int min = 0;
  int guesses = 0;
  int guess;
  int upperBound = max;
  int lowerBound = min;
  char test[256];
  string input;

  if(argc > 3){
    cout << "Incorrect number of arguments." << endl;
    return 1;
  }else if(argc == 2){
    max = atoi(argv[1]);
  }else if(argc == 3){
    min = atoi(argv[1]);
    max = atoi(argv[2]);
  }

  stringstream inputS;
  cout << endl;
  cout << "You need to choose a number between " << min << " and " << max << "." << endl;
  cout << "I will guess it in about " << log2(max - min) << " guesses." << endl;
  cout << "Keep it in your mind." << endl;
  do{
    cout << "I will try to guess it; are you ready?[y/n]" << endl;
    cin.getline(test, 255);
    input = test;
  }while(input.length() > 1 || (input[0] != 'y' && input[0] != 'n'));

  if(input[0] == 'n'){
    cout << "O, ok..Bye!" << endl;
    return 0;
  }

  while(true){
    ++guesses;
    guess = (upperBound + lowerBound) / 2;
    do{
      cout << "Ok, is your number above, below, or equal to:\t" << guess << "?[a/b/e]" << endl;
      cin.getline(test, 255);
      input = test;
    }while(input[0] != 'a' && input[0] != 'b' && input[0] != 'e');

    if(input[0] == 'a'){
      lowerBound = guess;
    }else if(input[0] == 'b'){
      upperBound = guess;
    }else if(input[0] == 'e'){
      cout << "AHA!! I win.  Your number was " << guess << "." << endl;
      cout << "I got it in " << guesses << " guesses." << endl;
      cout << "I told you I could get it." << endl;
      cout << "Better luck next time! :)" << endl;
      return 0;
    }else if(upperBound == lowerBound){
      cout << "What the hell?" << endl;
      cout << "How'd you do that?" << endl;
      cout << "O well, you win. :(" << endl;
      return 1;
    }
  }

  return 0;
}

