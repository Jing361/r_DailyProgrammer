#ifndef __ROOM_H__
#define __ROOM_H__

#include<string>

using std::string;

class Room{
public:
  string text;

  Room* north;
  Room* south;
  Room* east;
  Room* west;
};

#endif

