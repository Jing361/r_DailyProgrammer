#include<iostream>
#include<string>
#include<vector>
#include<stack>

#include<set>

std::vector<std::string> generateSuccessors(std::string state, std::string source){
  std::vector<std::string> ret;
  for(auto it = source.begin(); it != source.end(); ++it){
    ret.push_back(state + *it);
  }
  return ret;
}

void bfs(std::vector<std::string>& words, std::string source){
  std::stack<std::string> frontier;
  std::set<std::string> explored;

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
      }
      frontier.push(*it);
    }
  }
}

int main(){
  std::string str("hi!");
  std::vector<std::string> words;

  bfs(words, str);

  for(auto it = words.begin(); it != words.end(); ++it){
    std::cout << *it << std::endl;
  }

  return 0;
}

