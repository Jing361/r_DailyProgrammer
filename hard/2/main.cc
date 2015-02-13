#include<iostream>
#include<ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char** argv){
  time_t start;
  time_t stop;
  char cinput[256];
  string sinput;

  cout << "This is a stopwatch." << endl;
  while(true){
    cout << "When you want to start tracking time, press enter." << endl;
    cout << "While the timer is running, you can stop the timer, or lap it." << endl;
    cout << "Type 's' to stop it and 'l' to lap." << endl;
    cout << "If you want to quit, type 'q'." << endl;
    cin.getline(cinput, 255);
    time(&start);

    sinput = cinput;
    if(sinput[0] == 'q'){
      break;
    } else {
      cout << "Starting.." << endl;
    }

    while(true){
      do{
        cin.getline(cinput, 255);
        sinput = cinput;
      }while(sinput[0] != 's' && sinput[0] != 'l');

      if(sinput[0] == 's'){
        time(&stop);
        cout << "Time elapsed:\t" << difftime(stop, start) << endl;
        break;
      }else if(sinput[0] == 'l'){
        time(&stop);
        cout << "Lap:\t" << difftime(stop, start) << endl;
      }
    }
  }

  cout << "Quitting.." << endl;

  return 0;
}

