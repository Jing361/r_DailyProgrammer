#include<iostream>
#include<limits>

using namespace std;

int main(){
  unsigned long long sum = 1;
  unsigned long area = 1;
  unsigned long base = 1;

  while( sum < 169179692512835000 ){
    sum += ( area + base + 2 );
    base += 2;
    area += base;
  }

  cout << area << endl;

  return 0;
}

