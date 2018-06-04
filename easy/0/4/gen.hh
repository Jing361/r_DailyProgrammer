#ifndef __RGEN_H__
#define __RGEN_H__

#include<cstdlib>
#include<ctime>

class rGen{
private:
  int min, max;

public:
  rGen( int low, int high );

  int operator()();
};

#endif

