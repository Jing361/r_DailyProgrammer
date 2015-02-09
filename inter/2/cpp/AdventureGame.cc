#include"AdventureGame.hh"

AdventureGame::AdventureGame(){
  Room* tempR;

  tempR = new Room;
  tempR->text = string("Welcome to this game!\n");
  this->world.insert(pair<string, Room>("MainMenu", *tempR) );
  this->current = tempR;

  tempR = new Room;
  tempR->text = string("This is the beginning\n");
  this->world.insert(pair<string, Room>("StartRoom", *tempR) );
  world["MainMenu"].north = tempR;

  tempR = new Room;
  tempR->text = string("Winrar!\n"); 
  this->world.insert(pair<string, Room>("WinningRoom", *tempR) );
  world["StartRoom"].north = tempR;

  tempR = new Room;
  tempR->text = string("Losar!\n"); 
  this->world.insert(pair<string, Room>("LosingRoom", *tempR) );
  world["StartRoom"].south = tempR;
  world["StartRoom"].east = tempR;
  world["StartRoom"].west = tempR;

  this->running = false;
}

AdventureGame::~AdventureGame(){
}

void AdventureGame::run(){
  this->running = true;
  this->loop();
}

void AdventureGame::loop(){
  while(this->running){
    this->render();
    this->tick();
  }
}

void AdventureGame::render(){
  cout << this->current->text << endl;
}

void AdventureGame::tick(){
  int opt;

  cout << "Select an option." << endl;
  cin >> opt;
  cout << opt << endl;
  switch(opt){
  case 1:
    this->current = this->current->north;
  break;
  case 2:
    this->current = this->current->south;
  break;
  case 3:
    this->current = this->current->east;
  break;
  case 4:
    this->current = this->current->west;
  break;
  }
}

