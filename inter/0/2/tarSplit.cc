#include<fstream>
#include<string>

void tarSplit(std::string input){
  std::ifstream file(input, std::ios::binary | std::ios::ate);
  int tarSize = file.tellg();
  char* mem = new char[tarSize];
  int idx = 0;

  file.seekg(0);
  file.read(mem, tarSize);

  while(idx < tarSize){
    std::string fileName(&mem[idx], 100);
    std::ofstream out(fileName);
    std::string sizeStr(&mem[idx + 124], 12);
    if(sizeStr[10] == '\0') break;
    int fileSize = stoi(sizeStr, 0, 8);
    idx += 512;

    for(int i = idx; i < idx + fileSize; ++i){
      out << mem[i];
    }
    out << std::flush;

    idx += fileSize;
    while(idx % 512 != 0){
      ++idx;
    }
  }

  delete mem;
  return;
}

