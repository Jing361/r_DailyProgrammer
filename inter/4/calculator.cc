#include"calculator.hh"

calculator::calculator():acc(0){
  for(int i = (int)'0'; i <= (int)'9'; ++i){
    this->precedence.insert(std::pair<char, int>((char)i, 0));
  }
  this->precedence.insert(std::pair<char, int>('*', 2));
  this->precedence.insert(std::pair<char, int>('/', 2));
  this->precedence.insert(std::pair<char, int>('+', 1));
  this->precedence.insert(std::pair<char, int>('-', 1));
}

calculator::calculator(std::string str):calculator(){
  this->parse(str);
}

int calculator::evaluate(){
  while(!stk.empty()){
    if(precedence[stk.top()] == 0){
      eval.push(stk.top());
      stk.pop();
    }else if(precedence[stk.top()] > 0){
      this->evaluate();
    }
  }
  return acc;
}

void calculator::parse(std::string str){
  std::stack<char> stk;
  std::stack<char> ops;
  while(!stk.empty())
    this->stk.pop();
  while(!eval.empty())
    this->eval.pop();

  for(auto it = str.begin(); it != str.end(); ++it){
    if(this->precedence[*it] == 0){
      stk.push(*it);
    } else if(this->precedence[*it] > 0){
      while(!ops.empty() && this->precedence[*it] <= stk.top()){
        stk.push(ops.top());
        ops.pop();
      }
      ops.push(*it);
    }
  }
  while(!ops.empty()){
    stk.push(ops.top());
    ops.pop();
  }

//reverse stack order
  while(!stk.empty()){
    this->stk.push(stk.top());
    stk.pop();
  }
}

