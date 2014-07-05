#include<iostream>
using std::cout;
using std::endl;

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
        calendar[i] = new struct event;
    }

    while(choice != 4){
        cout << " ======================================" << endl;
        cout << "|\t\t\t\t\t|" << endl;
        cout << "|\t1. View events\t\t\t|" << endl;
        cout << "|\t2. Add event\t\t\t|" << endl;
        cout << "|\t3. Delete event\t\t\t|" << endl;
        cout << "|\t4. Exit\t\t\t\t|" << endl;
        cout << "|\t\t\t\t\t|" << endl;
        cout << " ======================================" << endl;
        cout << "Choose an option: ";
        scanf("%d", &choice);
        getchar();
        switch(choice){
            // Show events
            case 1:{
                cout << "Event listing: ";
                for(i = 0; i < numEvent; i++){
                    cout << "Date:" << calendar[i]->date << endl << "Event:" << eventList[calendar[i]->event] << endl;
                }
                cout << "" << endl;
            }break;
            // Create event
            case 2:{
                int time;
                int thing;

                cout << "When would you like to schedule: ";
                scanf("%d", &time);
                cout << "What would you like to schedule: ";
                scanf("%d", &thing);
                calendar[numEvent]->date = time;
                calendar[numEvent]->event = thing - 1;
                numEvent++;
            }break;
            // Delete event
            case 3:{
                int time;

                cout << "When would you like to unschedule: ";
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
                cout << "Exiting.." << endl;
            }break;
            default:{
                cout << "Invalid option! Try again." << endl;
            break;
            }
        }
    }

    return 0;
}

