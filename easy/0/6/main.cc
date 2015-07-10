#include<iostream>
#include<iomanip>

int main(){
  unsigned int prec;
  double pi = 0.0;
  int sign = 1;

  std::cout << "enter level of precision " << std::endl;
  std::cin >> prec;
  for(unsigned int i = 0; i < prec; ++i){
    pi += (4.0/((i * 2.0) + 1.0)) * sign;
    sign *= -1;
  }

  std::cout << std::setprecision(15) << pi << std::endl;

  return 0;
}

