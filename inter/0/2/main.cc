#include<iostream>
#include"AdventureGame.hh"

int main(int argc, char** argv){
  if(argc == 2){
    Game* game = new AdventureGame(argv[1]);
    game->run();
  } else {
    std::cout << "Need a file name." << std::endl;
  }
  return 0;
}

