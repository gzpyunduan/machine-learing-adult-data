#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "ID3.h"

int main(int argc,char* argv[]){
  ID3 id3(14);

  ifstream dataFile(argv[1]);
  if (dataFile.fail()){
    cout << "打开数据文件错误!" << endl;
    exit(0);
  }
  string line;
  while(getline(dataFile, line)){
    //cout << line << endl;
    adult adu(line);
    /*for (int i = 0; i < 15; i++){
      cout << adu.attr[i] << ' ';
    }
    cout << endl;*/
    id3.push(adu);
  }
  id3.build();
  //id3.print();
  dataFile.close();

  ifstream testFile(argv[2]);
  if (testFile.fail()){
    cout << "打开测试文件错误!" << endl;
    exit(0);
  }
  int num = 0;
  int cor_num = 0;
  while(getline(testFile, line)){
    num++;
    //cout << line;
    adult adu(line);
    if (id3.match(adu) == adu.attr[14])
      cor_num++;
  }
  cout << (double)cor_num / (double)num;

  return 0;
}
