#include"AdventureGame.hh"

int main(){
  Game& game = *new AdventureGame;
  game.run();
  return 0;
}

