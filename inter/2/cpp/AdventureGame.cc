#include"AdventureGame.hh"

/*AdventureGame::AdventureGame(){
  Room* tempR;

  tempR = new Room;
  tempR->text = string("Welcome to this game!\n");
  this->world.insert(pair<string, Room>("MainMenu", *tempR) );
  this->current = tempR;

  tempR->north = new Room;
  tempR = tempR->north;
  //tempR = new Room;
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
}*/
AdventureGame::AdventureGame(){
  this->world.insert(pair<string, Room*>("MainMenu", new Room) );
  this->world["MainMenu"]->text = string("Welcome to this game!\n");
  this->current = this->world["MainMenu"];

  this->world.insert(pair<string, Room*>("StartRoom", new Room) );
  this->world["StartRoom"]->text = string("This is the beginning!\n");
  this->world["MainMenu"]->north = this->world["StartRoom"];

  this->world.insert(pair<string, Room*>("WinningRoom", new Room) );
  this->world["WinningRoom"]->text = string("Winrar!\n");
  this->world["StartRoom"]->north = this->world["WinningRoom"];

  this->world.insert(pair<string, Room*>("LosingRoom", new Room) );
  this->world["LosingRoom"]->text = string("Losar!\n");
  this->world["StartRoom"]->south = this->world["LosingRoom"];
  this->world["StartRoom"]->east = this->world["LosingRoom"];
  this->world["StartRoom"]->west = this->world["LosingRoom"];

  this->running = false;
}

AdventureGame::~AdventureGame(){
/*
  for(std::map<string, Room*>::iterator it = map.begin(); it != map.end(); ++it){
    delete *it;
  }
*/
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

