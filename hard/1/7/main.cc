#include<iostream>
#include<vector>
#include"board.hh"
#include"player.hh"

int main(){
  board game;
  unsigned long turn = 0;
  std::vector<player*> players = { new human(Ecks), new ai(Oh, game) };

  while(!game){
    game.render();
    player* p = players[turn % 2];
    game.makePlay(p->getChoice(), p->getToken());
    ++turn;
  }
  game.render();
  std::cout << "Game over!" << std::endl;

  for(auto it:players){
    delete it;
  }
  return 0;
}

