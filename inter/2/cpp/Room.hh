#ifndef __ROOM_H__
#define __ROOM_H__

#include<string>
#include<vector>
#include"Action.hh"

using std::string;
using std::vector;

//Forward declaration.
class Action;//Lawsuit.

class Room{
public:
  //Printed to describe this room after it's been entered.
  string text;
  vector<Action*> actions;
};

#endif

