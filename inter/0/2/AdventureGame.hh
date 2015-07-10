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
  bool running;
  std::map<std::string, Menu*> world;
  Menu* current;

  void loop();
  void render();
  void tick();

public:
  AdventureGame();
  ~AdventureGame();
  void run();
};

#endif

