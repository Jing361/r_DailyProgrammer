#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct event{
  int date;
  char event[255];
}event;

void enumerate(event **list, unsigned int size);
void create(event **list, unsigned int size);
void remove(event **list, unsigned int size);

int main(int argc, char **argv){
  int i;
  int choice = 0;
  event *calendar[64];
  int numEvent = 0;

  for(i = 0; i < 64; ++i){
    calendar[i] = malloc(sizeof(event));
  }

  while(choice != 4){
    printf(" ======================================\n");
    printf("|\t\t\t\t\t|\n");
    printf("|\t1. View events\t\t\t|\n");
    printf("|\t2. Add event\t\t\t|\n");
    printf("|\t3. Delete event\t\t\t|\n");
    printf("|\t4. Exit\t\t\t\t|\n");
    printf("|\t\t\t\t\t|\n");
    printf(" ======================================\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar();
    switch(choice){
      // Show events
      case 1:{
        enumerate(calendar, numEvent);
      }break;
      // Create event
      case 2:{
        create(calendar, numEvent);
        ++numEvent;
      }break;
      // Delete event
      case 3:{
        remove(calendar, numEvent);
        --numEvent;
      }break;
      // Exit program
      case 4:{
        printf("Exiting..\n");
      }break;
      default:{
        printf("Invalid option! Try again.\n");
      }break;
    }
  }

  return 0;
}

void enumerate(event **list, unsigned int size){
  int i;
  printf("Event listing: ");
  if(size == 0){
    printf("No events!\n");
  } else {
    for(i = 0; i < size; ++i){
      printf("Date:%d\nEvent:%s\n\n", list[i]->date, list[i]->event);
    }
    printf("\n");
  }
}

void create(event **list, unsigned int size){
  int time;
  char thing[255];

  printf("When would you like to schedule?: ");
  scanf("%d", &time);
  printf("What would you like to schedule?: ");
  scanf("%s", thing);
  list[size]->date = time;
  strcpy(list[size]->event, thing);
}

void remove(event **list, unsigned int size){
  int time;
  int i;

  printf("What time would you like to unschedule?: ");
  scanf("%d", &time);
  for(i = 0; i < size; ++i){
    if(list[i]->date == time){
      int j;
      for(j = i + 1; j < size; ++j){
        list[j - 1] = list[j];
      }
      break;
    }
  }
}

