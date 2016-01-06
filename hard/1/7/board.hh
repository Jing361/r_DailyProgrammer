#ifndef __BOARD_HH__
#define __BOARD_HH__

#include<iostream>
#include"sharedTypes.hh"

class board{
private:
  world m_board{ {None, None, None},
                 {None, None, None},
                 {None, None, None} };

public:
  board();

  world& getModel();
  void render();
  void makePlay(unsigned int x, unsigned int y, marker token);
  void makePlay(Action act, marker token);
  operator bool();
};

#endif

