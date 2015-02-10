#include"AdventureGame.hh"
/*
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
*/
AdventureGame::AdventureGame(){
  this->world.insert(pair<string, Room*>("MainMenu", new Room) );
  this->world["MainMenu"]->text = string("Welcome to this game!\n");
  this->current = this->world["MainMenu"];

  this->world.insert(pair<string, Room*>("StartRoom", new Room) );
  this->world["StartRoom"]->text = string("This is the beginning!\n");
  this->world["MainMenu"]->north = new Action;
  this->world["MainMenu"]->north->desc = string("This is the first room.  It's messy.\n");
  this->world["MainMenu"]->north->next = this->world["StartRoom"];

  this->world.insert(pair<string, Room*>("WinningRoom", new Room) );
  this->world["WinningRoom"]->text = string("Winrar!\n");
  this->world["StartRoom"]->north = new Action;
  this->world["StartRoom"]->north->desc = string("This is the winning room.  It's glorious.\n");
  this->world["StartRoom"]->north->next = this->world["WinningRoom"];

  this->world.insert(pair<string, Room*>("LosingRoom", new Room) );
  this->world["LosingRoom"]->text = string("Losar!\n");
  this->world["StartRoom"]->south = new Action;
  this->world["StartRoom"]->south->desc = string("This is the losing room.  It's a sess pool.\n");
  this->world["StartRoom"]->south->next = this->world["LosingRoom"];
  this->world["StartRoom"]->east = 0;

  this->running = false;
}

AdventureGame::~AdventureGame(){
  for(std::map<string, Room*>::iterator it = world.begin(); it != world.end(); ++it){
    delete std::get<1>(*it);
  }
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
  cout << endl;
  if(this->current->north != 0)
    cout << "1.\t" << this->current->north->desc << endl;
  if(this->current->south != 0)
    cout << "2.\t" << this->current->south->desc << endl;
  if(this->current->east != 0)
    cout << "3.\t" << this->current->east->desc << endl;
  if(this->current->west != 0)
    cout << "4.\t" << this->current->west->desc << endl;
  cout << endl;
  cin >> opt;

  switch(opt){
  case 1:
    this->current = this->current->north->next;
  break;
  case 2:
    this->current = this->current->south->next;
  break;
  case 3:
    this->current = this->current->east->next;
  break;
  case 4:
    this->current = this->current->west->next;
  break;
  }
}

