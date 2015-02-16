#include"gen.hh"

rGen::rGen(int low, int high):min(low), max(high + 1){
  std::srand(std::time(0));
}

int rGen::operator()(){
  return (std::rand() % (this->max - this->min)) + this->min;
}

