#include<algorithm>
#include<random>
#include<iostream>
#include<chrono>
#include<vector>

class dice{
private:
  unsigned int m_count;
  std::mt19937 m_engine;
  std::uniform_int_distribution<unsigned int> m_dist;

  unsigned int gen(){
    return m_dist(m_engine);
  }

public:
  dice(unsigned int count, unsigned int sides = 6):
  m_count(count),
  m_engine(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
  m_dist(1, sides){
  }

  std::vector<unsigned int> roll(){
    std::vector<unsigned int> ret;
    for(unsigned int i = 0; i < m_count; ++i){
      ret.push_back(gen());
    }
    return ret;
  }

  template<class iterator>
  void roll(iterator first, iterator last){
    std::transform(first, last, first, [&](unsigned int val){
      return gen();
    });
  }
};

std::pair<unsigned int, unsigned int> translate(std::vector<unsigned int> v){
  return std::pair<unsigned int, unsigned int>(v[0], v[1]);
}

int main(){
  dice cDice(2);
  std::vector<unsigned int> rollv(cDice.roll());
  std::pair<unsigned int, unsigned int> roll = translate(rollv);
  unsigned int sum = roll.first + roll.second;

  for_each(rollv.begin(), rollv.end(), [](unsigned int val){
    std::cout << val << std::endl;
  });

  std::cout << sum << std::endl;

  while(true){
    //bet
    std::string response;
    bool pass;
    do{
      while(std::cout << "Bet pass/fail:\t" << std::flush && !(std::cin >> response)){
      }
    }while(response != "pass" && response != "fail");

    if(response == "pass"){
      pass = true;
    } else if(response == "fail"){
      pass = false;
    } else {
      std::cerr << "Wat hapn" << std::endl;
      return 1;
    }

    //come-out roll
    auto p = translate(cDice.roll());
    unsigned int val = p.first + p.second;
    unsigned int point;
    std::cout << "Your roll:" << val << std::endl;
    if(val == 2 || val == 3 || val == 12){
      std::cout << "Ya lose, kid" << std::endl;
      continue;
    } else if(val == 7 || val == 11){
      std::cout << "Ya win!" << std::endl;
      continue;
    } else {
      point = val;
    }

    //point roll
  }

  return 0;
}

