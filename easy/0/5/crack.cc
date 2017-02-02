#include<vector>
#include<string>
#include<iostream>
#include<fstream>

#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

using namespace std;

int main(){
  pid_t pid;
  vector<string> users;
  fstream userFile( "user" );
  string word;
  bool success = false;
  string infifo( "childout" );
  string outfifo( "parentout" );


  while( userFile >> word ){
    users.push_back( word );
    //dump salt and hash
    userFile >> word;
    userFile >> word;
  }

  userFile.close();
  mkfifo( infifo.c_str(), 0666 );
  mkfifo( outfifo.c_str(), 0666 );

  for( auto username : users ){
    string password = "a";

    while( !success ){
      switch( pid = fork() ){
      case -1:
        //fail
        cout << "fork failure" << endl;
        exit( 1 );
        break;

      case 0:
        //child
        {
          int fd[2];
          //string names are from parent's perspective
          fd[0] = open( outfifo.c_str(), O_RDONLY );
          fd[1] = open( infifo.c_str(), O_WRONLY );

          dup2( fd[0], 0 );
          dup2( fd[1], 1 );

          close( fd[0] );
          close( fd[1] );

          execl( "./main", NULL );
        }
        break;
     
      default:
        //parent
        {
          //try password
          ofstream outFile( outfifo );
          ifstream inFile( infifo );
          string result;
          string prompt1;
          string prompt2;

          inFile >> prompt1;
          outFile << username << endl;
          inFile >> prompt2;
          outFile << password << endl;

          //getline( inFile, result, '\n' );
          inFile >> result;
          inFile >> result;

          if( prompt1 != "username:" ){
            cout << "bad format for username.\t" << prompt1 <<  endl;
            exit( 1 );
          }
          if( prompt2 != "password:" ){
            cout << "bad format for password.\t" << prompt2 <<  endl;
            exit( 1 );
          }
          if( result == "win!" ){
            success = true;
          } else if( result == "lose!" ){
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
            exit( 1 );
          }
        }
        break;
      }
      kill( pid, SIGKILL );
      wait( NULL );
    }
    success = false;
    cout << username << '\t' << password << '\n';
  }

  unlink( infifo.c_str() );
  unlink( outfifo.c_str() );

  return 0;
}

