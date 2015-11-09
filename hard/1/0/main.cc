#include<iostream>
#include<string>

class hangman{
private:
  std::string m_word;
  unsigned int m_tries;
  unsigned int m_attempts = 0;
  bool m_hasWon = false;
  std::string m_guess;

public:
  hangman(std::string target, unsigned int tries = 4):
    m_word(target),
    m_tries(tries),
    m_guess(m_word.length(), ' '){
  }

  bool guess(char c){
    std::string::size_type pos = m_word.find(c);
    if(pos != std::string::npos){
      m_guess[pos] = m_word[pos];
      return true;
    }
    ++m_attempts;
    return false;
  }

  bool hasWon(){
    return m_guess.find(" ") == std::string::npos;
  }

  bool isOver(){
    return m_attempts >= m_tries || hasWon();
  }

  std::string guessState(){
    return m_guess;
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
    std::cout << "Guess a letter:\t" << std::endl;
    do{
      std::cin >> guess; 
    }while(guess.length() != 1);
    if(game.guess(guess[0])){
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Letter not found." << std::endl;
    }
    std::cout << game.guessState() << std::endl;
  }while(!game.isOver());

  if(game.hasWon()){
    std::cout << "Victory!" << std::endl;
  } else {
    std::cout << "Failure." << std::endl;
  }

  return 0;
}

