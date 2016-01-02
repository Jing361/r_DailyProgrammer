#ifndef __BOARD_HH__
#define __BOARD_HH__

#include<iostream>
#include"sharedTypes.hh"

class board{
private:
  marker m_board[3][3]{ {None, None, None},
                        {None, None, None},
                        {None, None, None} };

public:
  board();

  void render();
  operator bool();
};

#endif

