#include<iostream>
#include<limits>
#include<queue>
#include<set>
#include"board.hh"
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

Action human::getChoice(){
  unsigned int x, y;
  while(std::cout << "Input 2 integers as coordinates on the grid:\t" << std::flush && !(std::cin >> x >> y)){
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input." << std::endl;
  }
  return Action(x, y);
}

ai::ai(marker token, board& model):
  player(token),
  m_model(model){
}

std::vector<ai::Node> ai::expand(ai::Node node){
}

std::vector<Action> ai::bfs(){
  std::queue<ai::Node> frontier;
  std::set<ai::Node> explored;

  frontier.push(ai::Node(std::vector<Action>(), m_model));
  while(!frontier.empty()){
    auto thisNode = frontier.front();
    frontier.pop();

    explored.insert(thisNode);
    std::vector<ai::Node> nodes(expand(thisNode));
    for(auto it:nodes){
      if(explored.count(it) > 0){
        continue;
      }
      frontier.push(it);
    }
  }
}

Action ai::getChoice(){
  std::cout << "Thinking..." << std::endl;
  return Action(0, 0);
}

