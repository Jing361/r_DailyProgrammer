#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<queue>
#include<stack>
#include<set>
#include<limits>

typedef std::array<unsigned int, 3> world;
typedef std::pair<unsigned int, unsigned int> Action;

class player{
private:
  std::string prefix;
  std::string suffix;

public:
  player(int num):
    prefix(std::string("Player")),
    suffix(std::to_string(num)){
  }
  virtual ~player(){  }
    
  std::string getName(){
    return prefix + suffix;
  }
  virtual Action getChoice() = 0;
};

class human:public player{
public:
  human(int num):
    player(num){
  }
  virtual ~human(){ }

  Action getChoice(){
    unsigned int group, num;
    while(std::cout << "Specify which group, and how many to take." << std::endl &&
          !(std::cin >> group >> num)){
      std::cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input" << std::endl;
    }
    std::cout << std::endl << std::endl;

    return Action(group, num);
  }
};

class ai:public player{
private:
  world& nim;
  typedef std::pair<std::vector<Action>, world> Node;

  std::vector<Action> bfs(){
    std::queue<Node> frontier;
    std::set<Node> explored;
    std::vector<Node> answer;

    frontier.push(Node(std::vector<Action>(), nim));
    while(!frontier.empty()){
      auto thisNode = frontier.front();
      frontier.pop();

      explored.insert(thisNode);

      bool over = true;
      for(auto it = thisNode.second.begin(); it != thisNode.second.end(); ++it){
        if(*it > 0){
          over = false;
          break;
        }
      }
      if(over){
        if(thisNode.first.size() % 2 == 0){
          return thisNode.first;
        }
      }

      std::vector<Node> nodes = expand(thisNode);
      for(auto it = nodes.begin(); it != nodes.end(); ++it){
        if(explored.count(*it) > 0){
          continue;
        }
        frontier.push(*it);
      }
    }
    //backup scenario.  remove 1 from the first available.
    std::cout << "SHIT" << std::endl;
  }

  std::vector<Node> expand(Node node){
//typedef std::array<unsigned int, 3> world;
//typedef std::pair<unsigned int, unsigned int> Action;
//typedef std::pair<std::vector<Action>, world> Node;
//typedef std::array<unsigned int, 3> world;
    std::vector<Node> ret;
    unsigned int col = 1;

    for(auto it = node.second.begin(); it != node.second.end(); ++it){
      for(unsigned int i = 1; i < *it; ++i){
        std::vector<Action> list(node.first);
        world w(node.second);

        w[col - 1] -= i;

        list.push_back(Action(col, i));
        ret.push_back(Node(list,w));
      }
      ++col;
    }

    return ret;
  }

public:
  ai(int num, world& arr):
    player(num),
    nim(arr){
  }
  virtual ~ai(){  }

  Action getChoice(){
    std::cout << "\tThinking..." << std::endl;
    return bfs().front();
  }
};

int main(){
/*  std::cout << "AI options are:\n";
  std::cout << "\tHuman Opponent\n";
  std::cout << "\tBFS\n";
  std::cout << "\tDFS\n";
  std::cout << "\tA*\n";
  std::cout << "\tIterative deepening\n";
  std::cout << "\tminimax\n";
  std::cout << "\tKnown win strat\n";*/
  world nim{ 3, 4, 5 };
  std::vector<player*> players{ new human(1), new ai(2, nim) };
  unsigned int now = 0;
  player* cur = players[now % 2];

  while(true){
    std::cout << cur->getName() << " it is your turn." << std::endl;
    for(auto it = nim.begin(); it != nim.end(); ++it){
      std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    Action response(0, 0);
    while((response = cur->getChoice()).first > 0 && 
          (nim[response.first - 1] < response.second)){
      std::cout << "Invalid input" << std::endl;
    }

    nim[response.first - 1] -= response.second;

    bool empty = true;
    for(auto it = nim.begin(); it != nim.end(); ++it){
      if(*it != 0){
        empty = false;
        break;
      }
    }
    if(empty){
      std::cout << "Game over!!" << std::endl;
      std::cout << cur->getName() << " wins!!" << std::endl;
      break;
    }

    cur = players[++now % 2];
  }

  for(auto it = players.begin(); it != players.end(); ++it){
    delete *it;
  }

  return 0;
}

