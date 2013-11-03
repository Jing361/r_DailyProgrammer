#include <stdio.h>

int main(int argc, char **argv){
    char name[255];
    int age;
    char username[255];
    FILE *fp;
    fp = fopen("record", "wt");

    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Username: ");
    scanf("%s", username);
    printf("Your name is %s, you are %d years old, your username is %s.\n", name, age, username);
    fprintf(fp, "Name: %s\nAge: %d\nUsername: %s\n", name, age, username);
    fclose(fp);

    return 0;
}
