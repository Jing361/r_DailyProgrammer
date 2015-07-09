#include"calculator.hh"

calculator::calculator():
  acc(0){
  for(int i = (int)'0'; i <= (int)'9'; ++i){
    precedence[(char)i] = 0;
  }
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['+'] = 1;
  precedence['-'] = 1;
}

calculator::calculator(std::string str):
  calculator(){
  parse(str);
}

int calculator::evaluate(){
  std::stack<char> eval;

  while(!rpn.empty()){
    if(precedence[rpn.back()] == 0){
      eval.push(rpn.back());
      rpn.erase(rpn.size());
    }else if(precedence[rpn.back()] > 0){
      if(eval.size() < 2){
        return -1;
      }
      int op1, op2, res;
      op1 = ((int)eval.top() - (int)'0');
      eval.pop();
      op2 = ((int)eval.top() - (int)'0');
      eval.pop();
      if(rpn.back() == '*'){
        res = op1 * op2;
      } else if(rpn.back() == '/'){
        res = op1 / op2;
      } else if(rpn.back() == '+'){
        res = op1 + op2;
      } else if(rpn.back() == '-'){
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
  rpn.clear();

  for(auto it = str.begin(); it != str.end(); ++it){
    if(precedence[*it] == 0){
      rpn += *it;
    } else if(precedence[*it] > 0){
      while(!ops.empty() && precedence[*it] <= rpn.back()){
        rpn += ops.top();
        ops.pop();
      }
      ops.push(*it);
    }
  }
  while(!ops.empty()){
    rpn += ops.top();
    ops.pop();
  }
}

