#include<iostream>
#include"Menu.hh"

Menu::Menu(std::string _name, std::string _prompt, std::vector<std::pair<std::string, std::string>> _choices = std::vector<std::pair<std::string, std::string>>()):
  name(_name),
  prompt(_prompt),
  choices(_choices){
}

Menu::~Menu(){
}

const std::string& Menu::getChoice(){
  if(choices.size() == 0){
    return Menu::menuend;
  }
  unsigned choice; 
  int i;
  do{ 
    i = 1;
    for (auto ch : choices){
      std::cout << i++ << ": " << ch.first << '\n';
    }
    std::cin >> choice; 
    --choice;
  }while (choice >= choices.size()); 
  return choices[choice].second; 
}

const std::string& Menu::getName() const{
  return name;
}

const std::string& Menu::getPrompt() const{
  return prompt;
}

void Menu::setDelegate(std::function<void(void)> callback){
  delegate = callback;
}

const std::string Menu::menuend{"END"};

