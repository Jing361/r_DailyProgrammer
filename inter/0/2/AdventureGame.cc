#include<fstream>
#include"Menu.hh"
#include"AdventureGame.hh"

AdventureGame::AdventureGame(std::string pname){
  std::fstream file(pname);
  std::string line;
  std::string name;
  std::string prompt;
  std::pair<std::string, std::string> pr;
  std::vector<std::pair<std::string, std::string>> opts;

  m_running = false;

  while(std::getline(file, line)){
    if(line.size() == 0 || line[0] == '#') continue;

    int delim = line.find(':');
    std::string tok = line.substr(0, delim);
    std::string val = line.substr(delim);
    if(tok == "room"){
      if(name == ""){
        name = val;
        continue;
      }
      name = val;
      Menu* tmp = new Menu(name, prompt, opts);
      m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

      name = "";
      prompt = "";
      pr.first = "";
      pr.second = "";
      opts.clear();
    } else if(tok == "greet"){
      prompt = val;
    } else if(tok == "choice"){
      pr.first = val;
    } else if(tok == "target"){
      pr.second = val;

      opts.push_back(pr);
      pr.first = "";
      pr.second = "";
    }
  }
  /*Menu* tmp;

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

*/
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
  m_current->callEntryDelegate(this);
  std::string tmp = m_current->getChoice();
  if(tmp == Menu::menuend){
    m_running = false;
  }else{
    m_current = m_world[tmp];
  }
}

