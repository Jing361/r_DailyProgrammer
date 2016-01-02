#include<iostream>
#include"board.hh"
#include"player.hh"

int main(){
  board game;
  human one(Ecks);
  ai two(Oh);

  while(!game){
    game.render();
    std::cout << "beep boop" << std::endl;
  }

  return 0;
}

