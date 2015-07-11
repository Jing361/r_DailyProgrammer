#include<iostream>
#include<string>
#include<vector>
#include<stack>

#include<set>

void bfs(std::vector<std::string>& words, std::string state, std::string source){
  std::stack<std::pair<std::string, std::string>> frontier;
  std::vector<std::pair<std::string, std::string>> explored;

  frontier.push(std::pair<std::string, std::string>(state, source));

  while(!frontier.empty()){
    auto thisnode = frontier.pop();
    explored.push_back();
  }
}

int main(){
  std::string str("hi!");
  std::vector<std::string> words;

  bfs(words, str, std::string(""));

  for(auto it = words.begin(); it != words.end(); ++it){
  }

  return 0;
}

