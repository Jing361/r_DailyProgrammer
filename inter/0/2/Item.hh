#ifndef __STUFF_H__
#define __STUFF_H__

#include<string>

class Item{
private:
  std::string m_name;
  std::string m_desc;

public:
  Item(std::string pName, std::string pDesc = "");
};

#endif

