#include<iostream>
#include<vector>
#include<array>
#include<limits>

int main(){
/*  std::cout << "AI options are:\n";
  std::cout << "\tHuman Opponent\n";
  std::cout << "\tBFS\n";
  std::cout << "\tDFS\n";
  std::cout << "\tA*\n";
  std::cout << "\tIterative deepening\n";
  std::cout << "\tminimax\n";
  std::cout << "\tKnown win strat\n";*/
  std::array<int, 3> nim{ 3, 4, 5 };
  unsigned int group, num;
  bool player1 = true;

  while(true){
    std::cout << "Player";
    if(player1){
      std::cout << "1";
    } else {
      std::cout << "2";
    }
    std::cout << " it is your turn." << std::endl;
    for(auto it = nim.begin(); it != nim.end(); ++it){
      std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    while(std::cout << "Specify which group, and how many to take." << std::endl &&
          !(std::cin >> group >> num) &&
          num <= nim[group - 1]){
      std::cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input" << std::endl;
    }
    std::cout << std::endl << std::endl;

    nim[group - 1] -= num;
    player1 = !player1;
  }

  return 0;
}

