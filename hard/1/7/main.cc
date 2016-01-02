#include<iostream>
#include<utility>
#include"board.hh"

typedef std::pair<unsigned int, unsigned int> Action;

class player{
public:
  virtual ~player(){  }
  virtual Action getChoice() = 0;
};

class human:public player{
public:
  virtual ~human(){  }
  virtual Action getChoice(){
    unsigned int x, y;
    while(std::cout << "Input 2 integers as coordinates on the grid:\t" << std::flush && !(std::cin >> x >> y)){
      std::cout << "Invalid input." << std::endl;
    }
    return Action(x, y);
  }
};

class ai:public player{
public:
  virtual ~ai(){  }
  virtual Action getChoice(){
  }
};

int main(){
  board game;
  human one;

  game.render();

  return 0;
}

