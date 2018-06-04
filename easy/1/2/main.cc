#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>

using namespace std;

bool
prune( string target, string source ){
  map<char, int> count;
  map<char, int> comp;

  for( auto c : source ){
    ++count[c];
  }

  for( auto c : target ){
    ++comp[c];
  }

  return count != comp;
}

vector<string>
generateSuccessors( string state, string source ){
  vector<string> ret;

  for( auto it = source.begin(); it != source.end(); ++it ){
    ret.push_back( state + *it );
  }

  return ret;
}

vector<string>
bfs( string source ){
  stack<string> frontier;
  set<string> explored;
  vector<string> words;

  frontier.push( "" );

  while( !frontier.empty() ){
    auto thisnode = frontier.top();
    frontier.pop();
    explored.insert( thisnode );

    if( thisnode.length() == source.length() ){
      words.push_back( thisnode );
    }

    auto suc = generateSuccessors( thisnode, source );

    for( auto& successor : suc ){
      if( ( explored.count( successor ) > 0 )
       || ( successor.length() > source.length() ) ){
        continue;
      } else if( ( successor.length() == source.length() )
              && ( prune( successor, source ) ) ){
        continue;
      }

      frontier.push( successor );
    }
  }
  return words;
}

int
main( int argc, char** argv ){
  if( argc != 1 && argc != 2 ){
    cout << "Invalid number of arguments" << endl;
    return 1;
  }

  string str( "hi!" );
  str = "123456";
  if( argc == 2 ){
    str = argv[1];
  }
  vector<string> words;

  words = bfs( str );

  for( auto answer : words ){
    cout << answer << endl;
  }

  return 0;
}

