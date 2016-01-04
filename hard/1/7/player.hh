#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include<utility>
#include"sharedTypes.hh"

class player{
private:
  marker m_token;

public:
  player(marker token);

  virtual ~player(){  }
  virtual Action getChoice() = 0;
  marker getToken();
};

class human:public player{
public:
  human(marker token);

  virtual ~human(){  }
  virtual Action getChoice();
};

class ai:public player{
private:
  typedef std::pair<std::vector<Action>, world> Node;

  std::vector<Action> generateSuccessors();
  std::vector<Action> bfs();

public:
  ai(marker token);

  virtual ~ai(){  }
  virtual Action getChoice();
};

#endif

