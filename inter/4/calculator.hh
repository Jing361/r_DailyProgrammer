#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include<map>
#include<stack>
#include<string>

class calculator{
private:
  int acc;
  std::map<char, int> precedence;
  std::string rpn;
public:
  calculator();
  calculator(std::string str);
  void parse(std::string str);
  int evaluate();
};

#endif

