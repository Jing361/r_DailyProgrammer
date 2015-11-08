#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>

bool prune(std::string target, std::string source){
  std::map<char, int> count;
  std::map<char, int> comp;

  for(auto it = source.begin(); it < source.end(); ++it){
    count[*it]++;
  }

  for(auto it = target.begin(); it < target.end(); ++it){
    comp[*it]++;
  }

  if(count == comp){
    return false;
  } else {
    return true;
  }
}

std::vector<std::string> generateSuccessors(std::string state, std::string source){
  std::vector<std::string> ret;
  for(auto it = source.begin(); it != source.end(); ++it){
    ret.push_back(state + *it);
  }
  return ret;
}

std::vector<std::string> bfs(std::string source){
  std::stack<std::string> frontier;
  std::set<std::string> explored;
  std::vector<std::string> words;

  frontier.push(std::string(""));

  while(!frontier.empty()){
    auto thisnode = frontier.top();
    frontier.pop();
    explored.insert(thisnode);
    if(thisnode.length() == source.length()){
      words.push_back(thisnode);
    }
    auto suc = generateSuccessors(thisnode, source);
    for(auto it = suc.begin(); it != suc.end(); ++it){
      if((explored.count(*it) > 0) || ((*it).length() > source.length())){
        continue;
      } else if((*it).length() == source.length() && prune(*it, source)){
        continue;
      }
      frontier.push(*it);
    }
  }
  return words;
}

int main(int argc, char** argv){
  if(argc != 1 && argc != 2){
    std::cout << "Invalid number of arguments" << std::endl;
    return 1;
  }

  std::string str("hi!");
  if(argc == 2){
    str = argv[1];
  }
  std::vector<std::string> words;

  words = bfs(str);

  for(auto it = words.begin(); it != words.end(); ++it){
    std::cout << *it << std::endl;
  }

  return 0;
}

