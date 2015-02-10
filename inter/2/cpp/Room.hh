#ifndef __ROOM_H__
#define __ROOM_H__

#include<string>
#include"Action.hh"

using std::string;

//Forward declaration.
class Action;

class Room{
public:
  //Printed to describe this room after it's been entered.
  string text;

  Action* north;
  Action* south;
  Action* east;
  Action* west;
};

#endif

