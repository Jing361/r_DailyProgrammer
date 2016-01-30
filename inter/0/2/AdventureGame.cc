#include<fstream>
#include<dlfcn.h>
#include"Menu.hh"
#include"AdventureGame.hh"

AdventureGame::AdventureGame(std::string pname){
  std::fstream file(pname);
  std::string line;
  std::string name;
  std::string prompt;
  std::pair<std::string, std::string> pr;
  std::vector<std::pair<std::string, std::string>> opts;
  Menu::delegate entry = [](AdventureGame*, Menu*){};

  m_running = false;

  while(std::getline(file, line)){
    if(line.size() == 0 || line[0] == '#') continue;

    int delim = line.find(':');
    std::string tok = line.substr(0, delim);
    std::string val = line.substr(delim + 1);
    if(tok == "room"){
      if(name == ""){
        name = val;
        continue;
      }
      Menu* tmp = new Menu(name, prompt, opts);
      tmp->setEntryDelegate(entry);
      m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

      name = val;
      prompt = "";
      pr.first = "";
      pr.second = "";
      opts.clear();
      entry = [](AdventureGame*, Menu*){};
    } else if(tok == "greet"){
      prompt = val;
    } else if(tok == "entry"){
      char* error;
      void* tmp = dlsym(m_handle, val.data());
      if((error = dlerror()) != 0){
        std::cerr << "Couldn't find " << val << '\n';
        std::cerr << error << std::endl;
        //TODO:throw an exception here
      }

      entry = (void(*)(AdventureGame*, Menu*))tmp;
    } else if(tok == "choice"){
      pr.first = val;
    } else if(tok == "target"){
      pr.second = val;

      opts.push_back(pr);
      pr.first = "";
      pr.second = "";
    } else if(tok == "lib"){
      //TODO:if supporting multiple libs, need to provide support to close all of them correctly
      m_handle = dlopen(val.data(), RTLD_LAZY);
      if(!m_handle){
        std::cerr << "Failed to open library " << val << '\n';
        std::cerr << dlerror() << std::endl;
        //TODO:throw an exception here
      }
    }
  }
  //add the final room
  Menu* tmp = new Menu(name, prompt, opts);
  m_world.insert(std::pair<std::string, Menu*>(tmp->getName(), tmp));

  m_current = m_world["MainMenu"];
}

AdventureGame::~AdventureGame(){
  for(std::map<std::string, Menu*>::iterator it = m_world.begin(); it != m_world.end(); ++it){
    delete std::get<1>(*it);
  }
  dlclose(m_handle);
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

