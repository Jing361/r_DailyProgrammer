#include<stdio.h>
/*  LoTR vibe.  Antagonist isn't direct threat, real goal is to reach location, from there completion is easy.  */

void render();
void process();
void update();

typedef struct Stuff{
  Room* interact(){
  }
}Stuff;

typedef struct Door{
  Stuff stuff;

  Room next;

  Room* interact(){
  }
}Door;

typedef struct Room{
  Stuff north;
  Stuff south;
  Stuff east;
  Stuff west;
  char* text;
}Room;

int main(int argc, char** argv){
  bool running = true;
  Room* location;
  Room* mainMenu = new Room;
  while(running){
    render();
    process();
    update();
    printf("");
  }
  return 0;
}

