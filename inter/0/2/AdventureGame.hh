#ifndef __ADVENTUREGAME_H__
#define __ADVENTUREGAME_H__

#include<map>
#include<string>
#include<iostream>
#include<utility>
#include"Game.hh"
#include"Room.hh"
#include"Menu.hh"

class AdventureGame:public Game{
protected:
  bool m_running;
  std::map<std::string, Menu*> m_world;
  Menu* m_current;
  void* m_handle;

  void loop();
  void render();
  void tick();

public:
  AdventureGame(std::string name);
  ~AdventureGame();
  void run();
};

#endif

