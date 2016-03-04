#include<cstdlib>
#include<vector>
#include<iostream>

bool isPrime(long long num){
  for(long long i = 2; i < num - 1; ++i){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv){
  long long val = 2000;
  if(argc == 2){
    val = atoi(argv[1]);
  }
  std::vector<long long> primes;

  for(long long i = 2; i < val; ++i){
    if(isPrime(i)){
      primes.push_back(i);
    }
  }

  for(auto it:primes){
    std::cout << it << std::endl;
  }

  return 0;
}

