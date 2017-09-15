#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<exception>
#include<tuple>

using namespace std;

int main(){
  set<string> list;
  map<string, tuple<int, int> > people;
  set<tuple<string, string> > relations;

  // init list of scientists
  list.emplace( "Einstein" );
  list.emplace( "Feynmann" );
  list.emplace( "Gell-Mann" );
  list.emplace( "Thorne" );
  list.emplace( "Lorentz" );
  list.emplace( "Planck" );
  list.emplace( "Hilbert" );
  list.emplace( "Poincare" );
  list.emplace( "Noether" );

  // set initial position bounds
  for( auto person : list ){
    people.emplace( person, make_tuple( 1, list.size() ) );
  }

  // create set of smartness relations
  relations.emplace( "Einstein",  "Feynmann" );
  relations.emplace( "Feynmann",  "Gell-Mann" );
  relations.emplace( "Gell-Mann", "Thorne" );
  relations.emplace( "Einstein",  "Lorentz" );
  relations.emplace( "Lorentz",   "Planck" );
  relations.emplace( "Hilbert",   "Noether" );
  relations.emplace( "Poincare",  "Noether" );

  // increase minimum slot for smarter
  // decrease maximum slot for less-smart
  for( auto relation : relations ){
    ++get<0>( people[get<1>( relation )] );
    --get<1>( people[get<0>( relation )] );
  }

  vector<string> results( list.size() );

  for( auto person : list ){
    auto stats = people[person];

    // if slot is obvious, put it in
    if( get<0>( stats ) == get<1>( stats ) ){
      int slot = get<0>( stats );
      results[slot] = person;
    } else {
      //if the slot is less obvious, put it somewhere valid
      for( auto i = 0; i < list.size(); ++i ){
        if( i > get<0>( stats ) && i < get<1>( stats ) && results[i] == "" ){
          results[i] = person;
          break;
        }
      }
    }
  }

  for( auto name : results ){
    cout << name << endl;
  }

  return 0;
}

