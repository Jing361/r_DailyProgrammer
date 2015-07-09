#ifndef __ACTION_H__
#define __ACTION_H__

#include<string>
#include<functional>
#include"Room.hh"

using std::string;
using std::function;

//Forward declaration.
class Room;

class Action{
public:
  //Printed to describe this action before it's taken.
  string desc;
  
  Room* next;
  function<void(void)> func;
};

#endif

