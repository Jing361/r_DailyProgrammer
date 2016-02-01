#ifndef __PLAYER_HH__
#define __PLAYER_HH__

class Player{
private:
  int m_health;
  std::vector<Item*> m_items;

public:
  void addItem(Item* itm);
};

#endif

