#ifndef __ADVENTUREGAME_H__
#define __ADVENTUREGAME_H__

#include<map>
#include<string>
#include<iostream>
#include<utility>
#include<vector>
#include"Game.hh"
#include"Room.hh"
#include"Menu.hh"
#include"Player.hh"

class AdventureGame:public Game{
protected:
  bool m_running;
  std::map<std::string, Menu*> m_world;
  Menu* m_current;
  std::vector<void*> m_handles;
  std::vector<Player*> m_players;
  Player* m_player;

  void loop();
  void render();
  void tick();

public:
  AdventureGame(std::string name);
  ~AdventureGame();

  void run();
  void addPlayer(Player* plyr);
  void setMain(Palyer* plyr);
};

#endif

