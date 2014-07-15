#include <stdio.h>

//TODO: Add checks for input types (numbers/letters etc)
int main(int argc, char **argv){
    char name[255];
    char age[5];
    char username[255];
    FILE *fp;
    fp = fopen("record", "wt");

    printf("Name: ");
    scanf("%s", name);

    printf("Age: ");
    scanf("%s", age);

    printf("Username: ");
    scanf("%s", username);

    printf("Your name is %s, you are %s years old, and your username is %s.\n", name, age, username);
    fprintf(fp, "Name: %s\nAge: %s\nUsername: %s\n", name, age, username);
    fclose(fp);

    return 0;
}

