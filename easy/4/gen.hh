#ifndef __RGEN_H__
#define __RGEN_H__

#include<random>

template<int min, int max>
class rGen{
private:
  std::default_random_engine genrtr;
  std::uniform_int_distribution<int> dist(min, max);
  auto dice = std::bind(dist, genrtr);
public:
  int operator();
};

#endif

