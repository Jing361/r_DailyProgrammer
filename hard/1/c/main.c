#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>

int eval(int high, int low);

int main(int argc, char **argv){
  char resp = 'n';
  int high = 100;
  int low = 1;
  int guess;

  if(argc == 2){
    char *endptr;
    long val;
    errno = 0;

    val = strtol(argv[1], &endptr, 10);
    if((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0)) {
      printf("Error parsing number parameter\n");
    } else if(endptr == argv[1]) {
      printf("No digits found, ignoring program parameter\n");
    } else {
      // If we got here, strtol() successfully parsed a number.
      high = val;
    }
  }

  printf("Choose a number between 1 and %d inclusively.\n", high);
  printf("Press enter to continue.");
  getchar();

  while(resp != 'y' && resp != 'Y'){
    guess = eval(high, low);
    printf("Is %d your number?\n(Y for correct number H for too high and L for too low)\n", guess);
    scanf(" %c", &resp);
    if(resp == 'h' || resp == 'H'){
      high = guess;
    } else if(resp == 'l' || resp == 'L'){
      low = guess;
    }
  }
  return 0;
}

int eval(int high, int low){
  return ((high - low)/2) + low;
}
