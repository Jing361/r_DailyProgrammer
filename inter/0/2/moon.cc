#include<iostream>
#include"AdventureGame.hh"
#include"Menu.hh"

extern "C"{

void mainDelegate(AdventureGame* ag, Menu* m){
  std::cout << "mainDelegate" << std::endl;
}

void startDelegate(AdventureGame* ag, Menu* m){
  std::cout << "startDelegate" << std::endl;
}

void winDelegate(AdventureGame* ag, Menu* m){
  std::cout << "winDelegate" << std::endl;
}

void loseDelegate(AdventureGame* ag, Menu* m){
  std::cout << "loseDelegate" << std::endl;
}

}

