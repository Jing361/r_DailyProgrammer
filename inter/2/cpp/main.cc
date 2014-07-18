#include"Door.hh"
#include"Room.hh"
#include"Stuff.hh"

int main(int argc, char** argv){
  Game& game = *new AdventureGame;
  game.run();
  return 0;
}

