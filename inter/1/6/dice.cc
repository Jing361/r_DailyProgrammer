#include"dice.hh"
#include<algorithm>

dice::dice(unsigned int count, unsigned int sides):
  m_count(count),
  m_engine(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
  m_dist(1, sides){
}

std::vector<unsigned int> dice::roll(){
  std::vector<unsigned int> ret;
  for(unsigned int i = 0; i < m_count; ++i){
    ret.push_back(gen());
  }
  return ret;
}

template<class iterator>
void dice::roll(iterator first, iterator last){
  std::transform(first, last, first, [&](unsigned int val){
    return gen();
  });
}

