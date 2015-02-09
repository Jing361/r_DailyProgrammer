#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class event{
public:
  int date;
  string evt;
  event(int d, string evnt){
    this->date = d;
    this->evt = evnt;
  }
};

void create(vector<event>& list);
void remove(vector<event>& list);
void enumerate(vector<event>& list);

int main(int argc, char **argv){
  int choice = 0;
  vector<event> calendar;

  while(choice != 4){
    cout << "+=======================================+" << endl;
    cout << "|\t\t\t\t\t|" << endl;
    cout << "|\t1. View events\t\t\t|" << endl;
    cout << "|\t2. Add event\t\t\t|" << endl;
    cout << "|\t3. Delete event\t\t\t|" << endl;
    cout << "|\t4. Exit\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t|" << endl;
    cout << "+=======================================+" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    getchar();
    switch(choice){
      // Show events
      case 1:{
        enumerate(calendar);
      }break;
      // Create event
      case 2:{
        create(calendar);
      }break;
      // Delete event
      case 3:{
        remove(calendar);
      }break;
      // Exit program
      case 4:{
        cout << "Exiting.." << endl;
      }break;
      default:{
        cout << "Invalid option! Try again." << endl;
      }break;
    }
  }

  return 0;
}

void enumerate(vector<event>& list){
  cout << "Event listing:" << endl;
  if(list.empty()){
    cout << "No events!" << endl;
  } else {
    for(std::vector<event>::iterator it = list.begin(); it != list.end(); ++it){
      cout << "Date:" << (*it).date << endl << "Event:" << (*it).evt << endl;
      cout << endl;
    }
  }
}

void create(vector<event>& list){
  int time;
  char thing[255];

  cout << "When would you like to schedule: ";
  cin >> time;
  cout << "What would you like to schedule: ";
  cin >> thing;
  list.push_back(event(time, string(thing) ) );
}

void remove(vector<event>& list){
  int time;

  cout << "When would you like to unschedule: ";
  cin >> time;
  for(std::vector<event>::iterator it = list.begin(); it != list.end(); ++it){
    if((*it).date == time){
      list.erase(it);
      break;
    }
  }
}

