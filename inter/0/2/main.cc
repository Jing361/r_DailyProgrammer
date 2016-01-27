#include"AdventureGame.hh"

int main(int argc, char** argv){
  Game* game;
  if(argc == 2){
    game = new AdventureGame(argv[1]);
  }
  game->run();
  return 0;
}

