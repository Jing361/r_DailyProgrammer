#ifndef __MENU_H__
#define __MENU_H__

#include<string>
#include<vector>
#include<functional>

class AdventureGame;

class Menu{
public:
  typedef std::function<void(AdventureGame*, Menu*)> delegate;

private:
  std::string name;
  std::string prompt;
  //choices should probably each include a callback
  std::vector<std::pair<std::string, std::string>> choices;
  delegate entryDelegate;

public:
  static const std::string menuend;

  Menu(std::string _name, std::string _prompt, std::vector<std::pair<std::string, std::string> > choices);
  virtual ~Menu();

  const std::string& getChoice();
  const std::string& getName() const;
  const std::string& getPrompt() const;
  void setEntryDelegate(delegate callback);
  void callEntryDelegate(AdventureGame* ag);
};

#endif

