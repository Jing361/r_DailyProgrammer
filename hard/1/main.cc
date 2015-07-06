#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>

int main(int argc, char** argv){
  int max = 100;
  int min = 0;
  int guesses = 0;
  int guess;
  char test[256];
  std::string input;

  if(argc > 3){
    std::cout << "Incorrect number of arguments." << std::endl;
    std::cout << "Expected at most 3." << std::endl;
    std::cout << "main [[min] max]" << std::endl;
    return 1;
  }else if(argc == 2){
    max = atoi(argv[1]);
  }else if(argc == 3){
    min = atoi(argv[1]);
    max = atoi(argv[2]);
  }
  int upperBound = max;
  int lowerBound = min;

  std::stringstream inputS;
  std::cout << std::endl;
  std::cout << "You need to choose a number between " << min << " and " << max << "." << std::endl;
  std::cout << "I will guess it in about " << log2(max - min) << " guesses." << std::endl;
  std::cout << "Keep it in your mind." << std::endl;
  do{
    std::cout << "I will try to guess your number; are you ready?[y/n]" << std::endl;
    std::cin.getline(test, 255);
    input = test;
  }while(input.length() > 1 || (input[0] != 'y' && input[0] != 'n'));

  if(input[0] == 'n'){
    std::cout << "O, ok..Bye!" << std::endl;
    return 0;
  }

  while(true){
    ++guesses;
    guess = (upperBound + lowerBound) / 2;
    do{
      std::cout << "Ok, is your number above, below, or equal to:\t" << guess << "?[a/b/e]" << std::endl;
      std::cin.getline(test, 255);
      input = test;
    }while(input[0] != 'a' && input[0] != 'b' && input[0] != 'e');

    if(input[0] == 'a'){
      lowerBound = guess;
    }else if(input[0] == 'b'){
      upperBound = guess;
    }else if(input[0] == 'e'){
      std::cout << "AHA!! I win.  Your number was " << guess << "." << std::endl;
      std::cout << "I got it in " << guesses << " guesses." << std::endl;
      std::cout << "I told you I could get it." << std::endl;
      std::cout << "Better luck next time! :)" << std::endl;
      return 0;
    }else if(upperBound == lowerBound){
      std::cout << "What the hell?" << std::endl;
      std::cout << "How'd you do that?" << std::endl;
      std::cout << "O well, you win. :(" << std::endl;
      return 1;
    }
  }

  return 0;
}

