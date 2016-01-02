#include<iostream>

enum marker{ None, Ecks, Oh };

class board{
private:
  marker m_board[3][3]{ {None, None, None},
                        {None, None, None},
                        {None, None, None} };

public:
  board();

  void render();
};

