#include<iostream>
#include<string.h>
using std::cout;
using std::cin;
using std::endl;

typedef struct event{
  int date;
  char event[255];
}event;

void enumerate(event **list, unsigned int size);
void create(event **list, unsigned int size);
void remove(event **list, unsigned int size);

int main(int argc, char **argv){
  int i;
  int choice = 0;
  event *calendar[64];
  int numEvent = 0;

  for(i = 0; i < 64; ++i){
    calendar[i] = new event;
  }

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
        enumerate(calendar, numEvent);
      }break;
      // Create event
      case 2:{
        create(calendar, numEvent);
        ++numEvent;
      }break;
      // Delete event
      case 3:{
        remove(calendar, numEvent);
        --numEvent;
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

void enumerate(event **list, unsigned int size){
  unsigned int i;
  cout << "Event listing:" << endl;
  if(size == 0){
    cout << "No events!" << endl;
  } else {
    for(i = 0; i < size; ++i){
      cout << "Date:" << list[i]->date << endl << "Event:" << list[i]->event << endl;
      cout << endl;
    }
  }
}

void create(event **list, unsigned int size){
  int time;
  char thing[255];

  cout << "When would you like to schedule: ";
  cin >> time;
  cout << "What would you like to schedule: ";
  cin >> thing;
  list[size]->date = time;
  strcpy(list[size]->event, thing);
}

void remove(event **list, unsigned int size){
  unsigned int i;
  int time;

  cout << "When would you like to unschedule: ";
  cin >> time;
  for(i = 0; i < size; i++){
    if(list[i]->date == time){
      unsigned int j;
      for(j = i + 1; j < size; j++){
        list[j - 1] = list[j];
      }
      break;
    }
  }
}

