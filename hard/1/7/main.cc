#include<iostream>
#include<vector>
#include"board.hh"
#include"player.hh"

int main(){
  board game;
  std::vector<player*> players = { new human(Ecks), new ai(Oh) };

  while(!game){
    game.render();
    std::cout << "beep boop" << std::endl;
  }

  for(auto it:players){
    delete it;
  }
  return 0;
}

