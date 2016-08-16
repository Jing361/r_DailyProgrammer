#include<sstream>
#include<fstream>
#include<map>
#include<iostream>
#include<string>
#include<regex>
#include<exception>
#include<set>
#include<cctype>
#include<locale>
#include<algorithm> 
#include<functional> 

using namespace std;

static inline string &ltrim( string &s ) {
  s.erase( s.begin(), find_if( s.begin(), s.end(), not1( ptr_fun<int, int>( ispunct ) ) ) );
  return s;
}

// trim from end
static inline string &rtrim( string &s ) {
  s.erase( find_if( s.rbegin(), s.rend(), not1( ptr_fun<int, int>( ispunct ) ) ).base(), s.end() );
  return s;
}

// trim from both ends
static inline string &trim( string &s ) {
  return ltrim( rtrim( s ) );
}

char specialUpper( char c ){
  return ( char )::toupper( c );
}

class story{
  set<string> chapters;

public:
  story( fstream& file ){
    string str;

    for( unsigned int i = 0; i < 9; ++i ){
      getline( file, str );
    }

    do{
      string ins( str.begin()+6, str.end() );

      transform( ins.begin(), ins.end(), ins.begin(), specialUpper );
      chapters.insert( ins );

      getline( file, str );
    }while( str != "" );
  }

  static bool isRoman( string str ){
    regex exp( "[VIXL]+\\." );
    return regex_search( str, exp );
  }

  bool isTitle( string tok ){
    transform( tok.begin(), tok.end(), tok.begin(), specialUpper );
    bool ret = false;

    for_each( chapters.begin(), chapters.end(), [&]( string chapter ){
      string::size_type pos = tok.find( chapter );
      //result is the last thing in the line
      if( pos != string::npos && tok.size() - ( pos + chapter.size() ) == 0 ){
        ret = true;
      }
    } );
    return ret;
  }
};

void printRoman( string str ){
  cout << str << "\t";
  if( story::isRoman( str ) )
    cout << "roman" << endl;
  else
    cout << "not roman" << endl;
}

int main( int argc, char** argv ){
  string str;
  if( argc == 2 ){
    str = argv[1];
  } else {
    str = "data/sherlock.txt";
  }

  fstream sher( str );
  map<string, unsigned int> counts;
  multimap<string, unsigned int> pages;
  story lock( sher );
  unsigned long page = 0;
  unsigned long line = 0;

  // doc parsing
  while( getline( sher, str ) ){
    if( ++line > 40 ){
      ++page;
    }
    if( !lock.isTitle( str ) ){
      stringstream ss( str );
      string word;
      while( ss >> word ){
        trim( word );
        transform( word.begin(), word.end(), word.begin(), [&]( char c ){
          return specialUpper( c );
        } );
        pages.insert( make_pair( word, page ) );
        ++counts[word];
      }
    }
  }

  //output
  string lineWord;
  for( auto it = pages.begin(); it != pages.end(); ++it ){
    if( counts[( *it ).first] < 30 ){
      if( lineWord != ( *it ).first ){
        lineWord = ( *it ).first;
        cout << endl << ( *it ).first << '\t';
      }

      cout << ( *it ).second << ", ";
    }
  }

  sher.close();
  return 0;
}

