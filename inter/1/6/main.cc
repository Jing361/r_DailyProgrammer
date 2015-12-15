#include<algorithm>
#include<random>
#include<iostream>
#include<chrono>
#include<vector>

/*
  std::mt19937::result_type seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 engine(seed);
  std::uniform_int_distribution<unsigned int> dist(0, 1000);
  dist(engine);
*/

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
  m_dist(0, sides){
  }

  std::vector<unsigned int> roll(){
    std::vector<unsigned int> ret;
    for(unsigned int i = 0; i < m_count; ++i){
      ret.push_back(gen());
    }
    return ret;
  }
};

int main(){
  dice cDice(2);
  std::vector<unsigned int> roll(cDice.roll());

  for_each(roll.begin(), roll.end(), [](unsigned int val){
    std::cout << val << std::endl;
  });

  return 0;
}

