#include<iostream>
#include<random>
#include<array>
#include<thread>

int main(){
  std::random_device generator;
  std::mt19937 engine{ generator() };
  std::uniform_int_distribution<int> dist(1, 255);
  std::array<unsigned int, 1000000> arr;

  for(auto it = arr.begin(); it != arr.end(); ++it){
    *it = dist(engine);
  }

  return 0;
}

