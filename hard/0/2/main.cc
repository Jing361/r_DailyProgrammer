#include<iostream>
#include<string>
#include<ctime>

int main(int argc, char** argv){
  time_t start;
  time_t stop;
  std::string sinput;

  std::cout << "This is a stopwatch." << std::endl;
  while(true){
    std::cout << "When you want to start tracking time, press enter." << std::endl;
    std::cout << "While the timer is running, you can stop the timer, or lap it." << std::endl;
    std::cout << "Type 's' to stop it and 'l' to lap." << std::endl;
    std::cout << "If you want to quit, type 'q'." << std::endl;
    std::cin >> sinput;
    time(&start);

    if(sinput[0] == 'q'){
      break;
    } else {
      std::cout << "Starting.." << std::endl;
    }

    while(true){
      do{
        std::cin >> sinput;
      }while(sinput[0] != 's' && sinput[0] != 'l');

      if(sinput[0] == 's'){
        time(&stop);
        std::cout << "Time elapsed:\t" << difftime(stop, start) << std::endl;
        break;
      }else if(sinput[0] == 'l'){
        time(&stop);
        std::cout << "Lap:\t" << difftime(stop, start) << std::endl;
      }
    }
  }

  std::cout << "Quitting.." << std::endl;

  return 0;
}

