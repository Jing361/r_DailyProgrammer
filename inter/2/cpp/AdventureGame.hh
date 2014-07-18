#ifndef __ADVENTUREGAME_H__
#define __ADVENTUREGAME_H__

#include"Game.hh"

class AdventureGame{
protected:
  Room menu;
  Room start;

  void loop();
  void render();
  void tick();

public:
  AdventureGame();
  ~AdventureGame();
};

#endif

