#include<iostream>
#include<string>

class hangman{
private:
  std::string m_word;
  unsigned int m_tries;
  unsigned int m_attempts = 0;

public:
  hangman(std::string target, unsigned int tries = 4):
    word(target),
    m_tries(tries){
  }

  bool guess(std::string word){
    ++m_attempts;
    if(word == m_word){
      return true;
    } else if(m_attempts >= m_tries){
      return false;
    }
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
  }while(game.guess(guess));

  return 0;
}

