#include<iostream>
#include<random>
#include<list>
#include<thread>

std::list<unsigned int> sort(std::list<unsigned int> v){
  if(v.size() == 1){
    return v;
  }

  unsigned int siz = v.size();
  std::list<unsigned int> one;
  std::list<unsigned int> two;
  while(v.size() > siz / 2){
    one.push_back(v.front());
    v.pop_front();
  }
  while(!v.empty()){
    two.push_back(v.front());
    v.pop_front();
  }

  one = sort(one);
  two = sort(two);

  std::list<unsigned int> ret;
  for(unsigned int i = 0; i < siz; ++i){
    if(one.front() < two.front()){
      ret.push_back(one.front());
      one.pop_front();
    } else {
      ret.push_back(two.front());
      two.pop_front();
    }
  }
  return ret;
}

int main(){
  std::random_device generator;
  std::mt19937 engine{ generator() };
  std::uniform_int_distribution<unsigned int> dist(0, 500);
  std::list<unsigned int> arr;

  for(unsigned int i = 0; i < 1000000; ++i){
    arr.push_back(dist(engine));
  }

  arr = sort(arr);

  return 0;
}

