#ifndef __ADVENTUREGAME_H__
#define __ADVENTUREGAME_H__

#include<map>
#include<string>
#include<iostream>
#include"Game.hh"
#include"Room.hh"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::map;
using std::pair;

class AdventureGame:public Game{
protected:
  bool running;
  map<string, Room> world;
  Room* current;

  void loop();
  void render();
  void tick();

public:
  AdventureGame();
  ~AdventureGame();
  void run();
};

#endif

