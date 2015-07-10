#include"Menu.hh"
#include"AdventureGame.hh"

AdventureGame::AdventureGame(){
  this->running = false;

  Menu* tmp;

  tmp = new Menu("MainMenu", "Welcome to the game!\n", std::vector<std::pair<std::string, std::string> >{
                {"This goes to the first room.", "StartRoom"}, 
                {"This is an instant lose.", "LosingRoom"},
                {"This is an instant win.", "WinningRoom"}
  });
  this->world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  tmp = new Menu("StartRoom", "This is the first room.  It's messy.\n", std::vector<std::pair<std::string, std::string> >{
                {"This goes to the winning room.", "WinningRoom"}, 
                {"This goes to the losing room.", "LosingRoom"}
  });
  this->world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  tmp = new Menu("WinningRoom", "This is the winning room.  It's glorious.\n", std::vector<std::pair<std::string, std::string> >{
  });
  this->world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  tmp = new Menu("LosingRoom", "This is the losing room.  It's a sess pool.\n", std::vector<std::pair<std::string, std::string> >{
  });
  this->world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  this->current = this->world["MainMenu"];

  this->running = false;
}

AdventureGame::~AdventureGame(){
  for(std::map<std::string, Menu*>::iterator it = world.begin(); it != world.end(); ++it){
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
  std::cout << this->current->getPrompt() << std::endl;
}

void AdventureGame::tick(){
  std::string tmp = this->current->getChoice();
  if(tmp == Menu::menuend){
    this->running = false;
  }else{
    this->current = this->world[tmp];
  }
}

