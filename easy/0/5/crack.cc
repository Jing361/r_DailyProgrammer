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
  string fifoName( "data" );


  while( userFile >> word ){
    users.push_back( word );
    //dump salt and hash
    userFile >> word;
    userFile >> word;
  }

  userFile.close();
  mkfifo( fifoName.c_str(), 0666 );

  for( auto username : users ){
    string password = "a";

    while( !success ){
      cout << "trying\t" << password << "\tfor\t" << username << '\t';

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
          fd[0] = open( fifoName.c_str(), O_WRONLY );
          fd[1] = open( fifoName.c_str(), O_RDONLY );

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
          ifstream inFile( fifoName );
          ofstream outFile( fifoName, ios::trunc );
          string result;
          string prompt1;
          string prompt2;

          outFile << username << endl;
          outFile << password << endl;

          getline( inFile, prompt1, '\t' );
          getline( inFile, prompt2, '\t' );
          (void)inFile.get();//dump \n
          getline( inFile, result, '\n' );

          if( prompt1 != "username:" ){
            cout << "bad format for username.\t" << prompt1 <<  endl;
            exit( 1 );
          }
          if( prompt2 != "password:" ){
            cout << "bad format for password.\t" << prompt2 <<  endl;
            exit( 1 );
          }
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
        break;
      }
      kill( pid, SIGKILL );
      wait( NULL );
    }
    success = false;
    cout << username << '\t' << password << '\n';
  }

  unlink( fifoName.c_str() );

  return 0;
}

