#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<limits>

class player{
private:
  std::string prefix;
  std::string suffix;

public:
  player(int num):
    prefix(std::string("Player")),
    suffix(std::to_string(num)){
  }
    
  std::string getName(){
    return prefix + suffix;
  }
  virtual std::pair<unsigned int, unsigned int> getChoice() = 0;
};

class human:public player{
public:
  human(int num):player(num){
  }

  std::pair<unsigned int, unsigned int> getChoice(){
    unsigned int group, num;
    while(std::cout << "Specify which group, and how many to take." << std::endl &&
          !(std::cin >> group >> num)){
      std::cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input" << std::endl;
    }
    std::cout << std::endl << std::endl;

    return std::pair<unsigned int, unsigned int>(group, num);
  }
};

class ai:public player{
public:
  ai(int num):player(num){
  }

  std::pair<unsigned int, unsigned int> getChoice(){
    return std::pair<unsigned int, unsigned int>(1, 1);
  }
};

int main(){
/*  std::cout << "AI options are:\n";
  std::cout << "\tHuman Opponent\n";
  std::cout << "\tBFS\n";
  std::cout << "\tDFS\n";
  std::cout << "\tA*\n";
  std::cout << "\tIterative deepening\n";
  std::cout << "\tminimax\n";
  std::cout << "\tKnown win strat\n";*/
  std::array<unsigned int, 3> nim{ 3, 4, 5 };
  std::vector<player*> players{ new human(1), new ai(2) };
  unsigned int now = 0;
  player* cur = players[now % 2];

  while(true){
    std::cout << cur->getName() << " it is your turn." << std::endl;
    for(auto it = nim.begin(); it != nim.end(); ++it){
      std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    std::pair<unsigned int, unsigned int> response(0, 0);
    while((response = cur->getChoice()).first > 0 && 
          (nim[response.first - 1] < response.second)){
      std::cout << "Invalid input" << std::endl;
    }

    nim[response.first - 1] -= response.second;

    bool empty = true;
    for(auto it = nim.begin(); it != nim.end(); ++it){
      if(*it != 0){
        empty = false;
        break;
      }
    }
    if(empty){
      std::cout << "Game over!!" << std::endl;
      std::cout << cur->getName() << " wins!!" << std::endl;
      break;
    }

    cur = players[++now % 2];
  }

  return 0;
}

