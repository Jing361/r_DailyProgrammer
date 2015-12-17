#include<algorithm>
#include<iostream>
#include<vector>
#include"dice.hh"

std::pair<unsigned int, unsigned int> translate(std::vector<unsigned int> v){
  return std::pair<unsigned int, unsigned int>(v[0], v[1]);
}

int main(){
  dice cDice(2);
  std::vector<unsigned int> rollv(cDice.roll());
  std::pair<unsigned int, unsigned int> roll = translate(rollv);
  unsigned int sum = roll.first + roll.second;
  long long credit = 100;

  //TODO: Should display the individual die
  while(credit > 0){
    //bet
    std::string response;
    bool pass;
    long long bet;

    std::cout << "You have " << credit << " credits remaining." << std::endl;
    do{
      while(std::cout << "Bet pass/fail:\t" << std::flush && !(std::cin >> response)){
        std::cout << "Invalid input." << std::endl;
      }
    }while(response != "pass" && response != "fail");

    while(std::cout << "Bet amount:\t" << std::flush && !(std::cin >> bet) && bet > credit && bet < 1){
      std::cout << "Invalid bet." << std::endl;
    }

    if(response == "pass"){
      pass = true;
    } else if(response == "fail"){
      pass = false;
    } else {
      std::cerr << "Wat hapn" << std::endl;
      return 1;
    }

    //come-out roll
    auto p = translate(cDice.roll());
    unsigned int val = p.first + p.second;
    unsigned int point = 0;
    bool rollPass;

    std::cout << "Come-out roll." << std::endl;
    std::cout << "Your roll:" << val << std::endl;
    if(val == 2 || val == 3 || val == 12){
      rollPass = false;
    } else if(val == 7 || val == 11){
      rollPass = true;
    } else {
      point = val;
    }

    if(point == 0){
      if(rollPass == pass){
        std::cout << "Ya win!" << std::endl;
        credit += bet;
        continue;
      } else {
        std::cout << "Ya lose, kid" << std::endl;
        credit -= bet;
        continue;
      }
    }

    //point roll
    int nroll = 0;

    std::cout << "Point roll." << std::endl;
    do{
      p = translate(cDice.roll());
      val = p.first + p.second;
      std::cout << "Roll number " << ++nroll << "\t" << val << std::endl;
    }while(val != 7 && val != point);

    if(val == 7){
      std::cout << "Ya lose, kid" << std::endl;
      credit -= bet;
      continue;
    } else if(val == point){
      std::cout << "Ya win!" << std::endl;
      credit += bet;
      continue;
    }
  }

  return 0;
}

