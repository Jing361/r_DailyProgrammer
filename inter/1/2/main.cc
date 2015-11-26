#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<sstream>

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

int main(int argc, char** argv){
  unsigned int num;
  if(argc != 2){
    while(std::cout << "Number:\t" && !(std::cin >> num)){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid" << std::endl;
    }
  } else {
    std::stringstream ss(argv[1]);
    ss >> num;
  }
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

