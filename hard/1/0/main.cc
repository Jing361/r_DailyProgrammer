#include<iostream>
#include<string>

class hangman{
private:
  std::string m_word;
  unsigned int m_tries;
  unsigned int m_attempts = 0;
  bool m_hasWon = false;

public:
  hangman(std::string target, unsigned int tries = 4):
    m_word(target),
    m_tries(tries){
  }

  bool guess(std::string word){
    ++m_attempts;
    if(word == m_word){
      m_hasWon = true;
      return true;
    }
    return false;
  }

  bool hasWon(){
    return m_hasWon;
  }

  bool isOver(){
    return m_attempts >= m_tries || hasWon();
  }
};

int main(int argc, char** argv){
  std::string word;

  if(argc > 2){
    std::cout << "Too many arguments!" << std::endl;
    return 1;
  } else if(argc == 2){
    word = argv[1];
  } else {
    std::cout << "Please enter a word to be guessed!" << std::endl;
    std::cin >> word;
  }

  hangman game(word);

  std::string guess;
  do{
    std::cout << "Make a guess:\t" << std::endl;
    std::cin >> guess; 
    game.guess(guess);
  }while(!game.isOver());

  if(game.hasWon()){
    std::cout << "Victory!" << std::endl;
  } else {
    std::cout << "Failure." << std::endl;
  }

  return 0;
}

