#include"AdventureGame.hh"

int main(){
  Game& game = *new AdventureGame("moon.adv");
  game.run();
  return 0;
}

