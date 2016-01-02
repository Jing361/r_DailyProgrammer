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
        case Ecks:
          std::cout << "X";
        break;
        case Oh:
          std::cout << "O";
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

