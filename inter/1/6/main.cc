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

  return 0;
}

