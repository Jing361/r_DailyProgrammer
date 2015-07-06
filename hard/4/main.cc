#include<iostream>
#include<string>
#include<vector>
#include<fstream>

int main(){
  std::ifstream file("values");
  std::vector<unsigned int> vals;
  unsigned int val;
  while(file >> val){
    vals.push_back(val);
  }

  while(vals.size() >= 3){
    unsigned int i = vals.back();
    vals.pop_back();
    unsigned int j = vals.back();
    vals.pop_back();
    unsigned int k = vals.back();
    vals.pop_back();
    if(i * j == k){
      std::cout << i << " * " << j << " == " << k << std::endl;
    }
    if(i * k == j){
      std::cout << i << " * " << k << " == " << j << std::endl;
    }
    if(j * k == i){
      std::cout << j << " * " << k << " == " << i << std::endl;
    }

    if(i / j == k){
      std::cout << i << " / " << j << " == " << k << std::endl;
    }
    if(i / k == j){
      std::cout << i << " / " << k << " == " << j << std::endl;
    }
    if(j / k == i){
      std::cout << j << " / " << k << " == " << i << std::endl;
    }

    if(i + j == k){
      std::cout << i << " + " << j << " == " << k << std::endl;
    }
    if(i + k == j){
      std::cout << i << " + " << k << " == " << j << std::endl;
    }
    if(j + k == i){
      std::cout << j << " + " << k << " == " << i << std::endl;
    }

    if(i - j == k){
      std::cout << i << " - " << j << " == " << k << std::endl;
    }
    if(i - k == j){
      std::cout << i << " - " << k << " == " << j << std::endl;
    }
    if(j - k == i){
      std::cout << j << " - " << k << " == " << i << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}

