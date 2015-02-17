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
  std::stack<char> eval;

  while(!this->rpn.empty()){
    if(precedence[this->rpn.back()] == 0){
      eval.push(this->rpn.back());
      this->rpn.erase(this->rpn.size());
    }else if(precedence[this->rpn.back()] > 0){
      if(eval.size() < 2){
        return -1;
      }
      int op1, op2, res;
      op1 = ((int)eval.top() - (int)'0');
      eval.pop();
      op2 = ((int)eval.top() - (int)'0');
      eval.pop();
      if(this->rpn.back() == '*'){
        res = op1 * op2;
      } else if(this->rpn.back() == '/'){
        res = op1 / op2;
      } else if(this->rpn.back() == '+'){
        res = op1 + op2;
      } else if(this->rpn.back() == '-'){
        res = op1 - op2;
      }
      eval.push(res);
    }
  }
  if(eval.size() == 1){
    return eval.top();
  } else {
    return eval.size();
  }
}

void calculator::parse(std::string str){
  std::stack<char> ops;
  this->rpn.clear();

  for(auto it = str.begin(); it != str.end(); ++it){
    if(this->precedence[*it] == 0){
      this->rpn += *it;
    } else if(this->precedence[*it] > 0){
      while(!ops.empty() && this->precedence[*it] <= this->rpn.back()){
        this->rpn += ops.top();
        ops.pop();
      }
      ops.push(*it);
    }
  }
  while(!ops.empty()){
    this->rpn += ops.top();
    ops.pop();
  }
}

