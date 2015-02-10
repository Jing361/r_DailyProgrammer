#ifndef __ACTION_H__
#define __ACTION_H__

#include<string>
#include"Room.hh"

using std::string;

//Forward declaration.
class Room;

class Action{
public:
  //Printed to describe this action before it's taken.
  string desc;
  
  Room* next;
};

#endif

