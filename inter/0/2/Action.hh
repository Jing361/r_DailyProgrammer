#ifndef __ACTION_H__
#define __ACTION_H__

#include<string>
#include<functional>
#include"Room.hh"

//Forward declaration.
class Room;

class Action{
public:
  //Printed to describe this action before it's taken.
  std::string desc;
  
  Room* next;
  std::function<void(void)> func;
};

#endif

