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

  void loop();
  void render();
  void tick();

public:
  AdventureGame();
  ~AdventureGame();
  void run();
};

#endif

