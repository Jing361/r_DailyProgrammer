#include"Menu.hh"
#include"AdventureGame.hh"

AdventureGame::AdventureGame(){
  m_running = false;

  Menu* tmp;

  tmp = new Menu("MainMenu", "Welcome to the game!\n",
                 std::vector<std::pair<std::string, std::string> >{
                   {"This goes to the first room.", "StartRoom"}, 
                   {"This is an instant lose.", "LosingRoom"},
                   {"This is an instant win.", "WinningRoom"}
                });
  m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  tmp = new Menu("StartRoom", "This is the first room.  It's messy.\n",
                 std::vector<std::pair<std::string, std::string> >{
                   {"This goes to the winning room.", "WinningRoom"}, 
                   {"This goes to the losing room.", "LosingRoom"}
                 });
  m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  tmp = new Menu("WinningRoom", "This is the winning room.  It's glorious.\n", std::vector<std::pair<std::string, std::string> >{
  });
  m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  tmp = new Menu("LosingRoom", "This is the losing room.  It's a cesspool.\n", std::vector<std::pair<std::string, std::string> >{
  });
  m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  m_current = m_world["MainMenu"];
}

AdventureGame::~AdventureGame(){
  for(std::map<std::string, Menu*>::iterator it = m_world.begin(); it != m_world.end(); ++it){
    delete std::get<1>(*it);
  }
}

void AdventureGame::run(){
  m_running = true;
  loop();
}

void AdventureGame::loop(){
  while(m_running){
    render();
    tick();
  }
}

void AdventureGame::render(){
  std::cout << m_current->getPrompt() << std::endl;
}

void AdventureGame::tick(){
  std::string tmp = m_current->getChoice();
  if(tmp == Menu::menuend){
    m_running = false;
  }else{
    m_current = m_world[tmp];
  }
}

