#include<algorithm>
#include<iostream>

#include<tools.hh>
#include<world.hh>
#include<maze.hh>

using namespace std;

int main(){
  world w = maze::generate( 7, 7 );
  position start = w.rand_edge();
  position end   = w.rand_edge();

  w[start] = location::START;
  w[end]   = location::END;

  w.print( cout );
  auto answers = maze::solve( w, start, end );

  auto shortest = *min_element( answers.begin(), answers.end(),
    []( const path& r1, const path& r2 ){
      return r1.size() < r2.size();
    }
  );

  for( unsigned int i = 0, j = 1; j < shortest.size(); ++i, ++j ){
    w.route( shortest[i], shortest[j] );
  }
  w.print( cout );

  return 0;
}

