#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include<utility>
#include<vector>
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
  typedef std::pair<std::vector<Action>, board> Node;

  board& m_model;

  std::vector<Node> expand(Node node);
  std::vector<Action> bfs();

public:
  ai(marker token, board& model);

  virtual ~ai(){  }
  virtual Action getChoice();
};

#endif

