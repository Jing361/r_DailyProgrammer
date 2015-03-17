#include"AdventureGame.hh"

AdventureGame::AdventureGame(){
  this->running = false;

  this->world.insert(pair<string, Room*>("MainMenu", new Room) );
  this->world.insert(pair<string, Room*>("StartRoom", new Room) );
  this->world.insert(pair<string, Room*>("WinningRoom", new Room) );
  this->world.insert(pair<string, Room*>("LosingRoom", new Room) );

  this->world["MainMenu"]->text    = string("Welcome to the game!\n");
  this->world["StartRoom"]->text   = string("This is the beginning!\n");
  this->world["WinningRoom"]->text = string("Winrar!\n");
  this->world["LosingRoom"]->text  = string("Losar!\n");

  this->world["MainMenu"]->actions.push_back(new Action);
  this->world["StartRoom"]->actions.push_back(new Action);
  this->world["StartRoom"]->actions.push_back(new Action);
  this->world["WinningRoom"]->actions.push_back(new Action);
  this->world["LosingRoom"]->actions.push_back(new Action);

  this->world["MainMenu"]->actions[0]->desc  = string("This is the first room.  It's messy.");
  this->world["StartRoom"]->actions[0]->desc = string("This is the winning room.  It's glorious.");
  this->world["StartRoom"]->actions[1]->desc = string("This is the losing room.  It's a sess pool.");
  this->world["WinningRoom"]->actions[0]->desc = string("You've won!  Good job.  Bye!");
  this->world["LosingRoom"]->actions[0]->desc = string("You've lost!  You suck.  Bye!");

  this->world["MainMenu"]->actions[0]->next  = this->world["StartRoom"];
  this->world["StartRoom"]->actions[0]->next = this->world["WinningRoom"];
  this->world["StartRoom"]->actions[1]->next = this->world["LosingRoom"];

  this->world["WinningRoom"]->actions[0]->func = [this]()->void{ this->running = false; };
  this->world["LosingRoom"]->actions[0]->func = [this]()->void{ this->running = false; };

  this->current = this->world["MainMenu"];

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
  char cinput[256];
  unsigned int opt;
  int i;

  do{
    i = 1;
    cout << "Select an option." << endl;
    cout << endl;
    for(auto it = this->current->actions.begin(); it != this->current->actions.end(); ++it, ++i){
      cout << i << ".\t" << (*it)->desc << endl;
    }
    cout << endl;
    cin.getline(cinput, 255);
    cout << endl;
    opt = std::stoi(string(cinput));
  }while(opt + 1 < this->current->actions.size());

  if(this->current->actions[opt - 1]->func){
    this->current->actions[opt - 1]->func();
  }

  this->current = this->current->actions[opt - 1]->next;
}

