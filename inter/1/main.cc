#include<iostream>
#include<vector>
#include<string>

class event{
public:
  int date;
  std::string evt;
  event(int d, std::string evnt){
    this->date = d;
    this->evt = evnt;
  }
};

void create(std::vector<event>& list);
void remove(std::vector<event>& list);
void enumerate(std::vector<event>& list);

int main(){
  int choice = 0;
  std::vector<event> calendar;

  while(choice != 4){
    std::cout << "+=======================================+" << std::endl;
    std::cout << "|\t\t\t\t\t|" << std::endl;
    std::cout << "|\t1. View events\t\t\t|" << std::endl;
    std::cout << "|\t2. Add event\t\t\t|" << std::endl;
    std::cout << "|\t3. Delete event\t\t\t|" << std::endl;
    std::cout << "|\t4. Exit\t\t\t\t|" << std::endl;
    std::cout << "|\t\t\t\t\t|" << std::endl;
    std::cout << "+=======================================+" << std::endl;
    std::cout << "Choose an option: ";
    std::cin >> choice;

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
        std::cout << "Exiting.." << std::endl;
      }break;
      default:{
        std::cout << "Invalid option! Try again." << std::endl;
      }break;
    }
  }

  return 0;
}

void enumerate(std::vector<event>& list){
  std::cout << "Event listing:" << std::endl;
  if(list.empty()){
    std::cout << "No events!" << std::endl;
  } else {
    for(auto it = list.begin(); it != list.end(); ++it){
      std::cout << "Date:" << (*it).date << std::endl;
      std::cout << "Event:" << (*it).evt << std::endl;
      std::cout << std::endl;
    }
  }
}

void create(std::vector<event>& list){
  int time;
  std::string thing;

  std::cout << "When would you like to schedule: ";
  std::cin >> time;
  std::cout << "What would you like to schedule: ";
  std::cin >> thing;
  list.push_back(event(time, thing));
}

void remove(std::vector<event>& list){
  int time;

  std::cout << "When would you like to unschedule: ";
  std::cin >> time;
  for(auto it = list.begin(); it != list.end(); ++it){
    if((*it).date == time){
      list.erase(it);
      break;
    }
  }
}

