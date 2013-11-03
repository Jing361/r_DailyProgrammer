#include<stdio.h>

int main(int argc, char **argv){
    int i;
    int choice = 0;
    struct event *calendar[64];
    char *eventList[8];
    int numEvent = 0;
    eventList[0] = "Birthday";
    eventList[1] = "Anniversary";
    eventList[2] = "Three";
    eventList[3] = "Four";
    eventList[4] = "Five";
    eventList[5] = "Six";
    eventList[6] = "Seven";
    eventList[7] = "Eight";

    struct event{
        int date;
        int event;
    };

    for(i = 0; i < 64; i++){
        calendar[i] = malloc(sizeof(struct event));
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
                printf("Event listing: ");
                for(i = 0; i < numEvent; i++){
                    printf("Date:%d\nEvent:%s\n\n", calendar[i]->date, eventList[calendar[i]->event]);
                }
                printf("\n");
            }break;
            // Create event
            case 2:{
                int time;
                int thing;

                printf("When would you like to schedule: ");
                scanf("%d", &time);
                printf("What would you like to schedule: ");
                scanf("%d", &thing);
                calendar[numEvent]->date = time;
                calendar[numEvent]->event = thing - 1;
                numEvent++;
            }break;
            // Delete event
            case 3:{
                int time;

                printf("When would you like to unschedule: ");
                scanf("%d", &time);
                for(i = 0; i < numEvent; i++){
                    if(calendar[i]->date == time){
                        int j;
                        for(j = i + 1; j < numEvent; j++){
                            calendar[j - 1] = calendar[j];
                        }
                        break;
                    }
                }
                numEvent--;
            }break;
            // Exit program
            case 4:{
                printf("Exiting..\n");
            }break;
            default:{
                printf("Invalid option! Try again.\n");
            break;
            }
        }
    }

    return 0;
}

