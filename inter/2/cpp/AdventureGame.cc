#include"AdventureGame.hh"

AdventureGame::AdventureGame(){
}

AdventureGame::~AdventureGame(){
}

void AdventureGame::run(){
  this->loop();
}

void AdventureGame::loop(){
  while(this->running){
    this->render();
    this->tick();
  }
}

