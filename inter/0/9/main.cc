#include<fstream>
#include<string>
#include<iostream>
#include<map>

int main(int argc, char** argv){
  if(argc != 3){
    std::cout << "Incorrect number of arguments." << std::endl;
    std::cout << "Expected usage: " << argv[0] << " input output." << std::endl;
    std::cout << "Where input and output are valid file names." << std::endl;
  }

  std::map<std::string, std::string> keywords;

  std::ifstream input(argv[1]);
  std::ifstream config("config");
  std::ofstream output(argv[2]);

  std::string key;
  std::string val;
  config >> str;
  config.getline(val);

  keywords[str] = val;

  //iterate through input file, writing to output.

  input.close();
  output.close();
  return 0;
}

