#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  unsigned long long int prec;
  double pi = 0.0;
  int sign = 1;

  while( cout << "Enter level of precision: " << endl && !( cin >> prec ) ){
  }

  for( unsigned long long int i = 0; i < prec; ++i ){
    pi += ( 4.0 / ( ( i * 2.0 ) + 1.0 ) ) * sign;
    sign *= -1;
  }

  cout << setprecision( prec ) << pi << endl;

  return 0;
}

