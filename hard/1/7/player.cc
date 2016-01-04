#include<iostream>
#include<limits>
#include"player.hh"

player::player(marker token):
  m_token(token){
}

marker player::getToken(){
  return m_token;
}

human::human(marker token):
  player(token){
}

ai::ai(marker token):
  player(token){
}

Action human::getChoice(){
  unsigned int x, y;
  while(std::cout << "Input 2 integers as coordinates on the grid:\t" << std::flush && !(std::cin >> x >> y)){
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input." << std::endl;
  }
  return Action(x, y);
}

std::vector<Action> ai::generateSuccessors(){
}

std::vector<Action> ai::bfs(){
  std::queue<Node> frontier;
  std::set<Node> explored;

  while(!frontier.empty()){
  }
}

Action ai::getChoice(){
  std::cout << "Thinking..." << std::endl;
  return Action(0, 0);
}

