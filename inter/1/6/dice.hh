#include<random>
#include<chrono>

class dice{
private:
  unsigned int m_count;
  std::mt19937 m_engine;
  std::uniform_int_distribution<unsigned int> m_dist;

  unsigned int gen(){
    return m_dist(m_engine);
  }

public:
  dice(unsigned int count, unsigned int sides = 6);

  std::vector<unsigned int> roll();
  template<class iterator>
  void roll(iterator first, iterator last);
};

