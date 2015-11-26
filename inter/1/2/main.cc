#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

unsigned int factor(unsigned int num){
  unsigned int i = 2;

  while(i < num){
    if(num % i == 0){
      break;
    }
    ++i;
  }

  return i;
}

int main(){
  unsigned int num = 12;
  std::vector<unsigned int> factors;

  while(num != 1){
    unsigned int next = factor(num);
    factors.push_back(next);
    if(next == 1){
      break;
    } else {
      num /= next;
    }
  }

  for_each(factors.begin(), factors.end(), [](unsigned int x){
    std::cout << x << std::endl;
  });

  return 0;
}

