#include"board.hh"

board::board(){
}

void board::render(){
  std::cout << "+-+-+-+\n";
  for(unsigned int i = 0; i < 3; ++i){
    std::cout << "|";
    for(unsigned int j = 0; j < 3; ++j){
      switch(m_board[i][j]){
        case None:
          std::cout << " ";
        break;
        case Oh:
          std::cout << "O";
        break;
        case Ecks:
          std::cout << "X";
        break;
        default:
          std::cout << "L";
        break;
      }
      std::cout << "|";
    }
    std::cout << "\n";
    std::cout << "+-+-+-+\n";
  }
  std::cout << std::flush;
}

void board::makePlay(unsigned int x, unsigned int y, marker token){
  m_board[x][y] = token;
}

void board::makePlay(Action act, marker token){
  makePlay(act.first, act.second, token);
}

board::operator bool(){
  //using a for loop makes this easier to expand for bigger boards
  bool ret = false;
  for(unsigned int i = 0; i < 3; ++i){
    ret = ret || ((m_board[i][0] == m_board[i][1] == m_board[i][2]) && m_board[i][0] != None);
    ret = ret || ((m_board[0][i] == m_board[1][i] == m_board[2][i]) && m_board[i][0] != None);
  }
  //TODO:Implement diagonal checks.
  return ret;
}

