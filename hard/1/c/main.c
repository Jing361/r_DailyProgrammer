#include<stdio.h>

int eval(int, int);

int main(int argc, char **argv){
  printf("Choose a number between 1 and 100 inclusively.\n");
  printf("Press enter to continue.");
  getchar();
  char resp = 'n';
  int high = 100;
  int low = 1;
  int guess;
  //TODO: let it terminate!! wtfff
  while(resp != 'y' && resp != 'Y'){
    guess = eval(high, low);
    printf("Is %d your number?\n(y or Y for correct numberh or H for too high and l or L for too low)\n", guess);
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

