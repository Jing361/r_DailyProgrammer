#include<iostream>
#include<random>
#include<vector>
#include<chrono>

void sort(std::vector<unsigned int>& v){
  //sublist size
  for(unsigned int i = 2; i <= v.size(); i *= 2){
    //current sublist starting index
    for(unsigned int j = 0; j < v.size(); j += i){
      std::vector<unsigned int> x;
      std::vector<unsigned int> y;
      std::vector<unsigned int> z;
      for(unsigned int k = j + i; k > j; --k){
        if(k <= j + (i / 2)){
          x.push_back(v[k - 1]);
        } else {
          y.push_back(v[k - 1]);
        }
      }
      while(x.size() > 0 || y.size() > 0){
        if(x.back() < y.back()){
          z.push_back(x.back());
          x.pop_back();
        } else {
          z.push_back(y.back());
          y.pop_back();
        }
      }
      for(unsigned k = 0; k < z.size(); ++k){
        v[j + k] = z[k];
      }
    }
  }
}

int main(){
  std::mt19937::result_type seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 engine(seed);
  std::uniform_int_distribution<unsigned int> dist(0, 1000);
  std::vector<unsigned int> arr;

  std::cout << "Generating list.." << std::endl;
  for(unsigned int i = 0; i < 1024; ++i){
    arr.push_back(dist(engine));
  }
  
  std::cout << "Sorting list.." << std::endl;
  sort(arr);
  std::cout << "List sorted!" << std::endl;

  return 0;
}
