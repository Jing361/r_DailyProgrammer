#ifndef __ADVENTUREGAME_H__
#define __ADVENTUREGAME_H__

#include<map>
#include<string>
#include<iostream>
#include<utility>
#include"Game.hh"
#include"Room.hh"
#include"Menu.hh"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::map;
using std::pair;

class AdventureGame:public Game{
protected:
  bool running;
  map<string, Menu*> world;
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

