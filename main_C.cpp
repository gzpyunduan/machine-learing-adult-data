#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "C4.5.h"

int main(int argc,char* argv[]){
  C45 Tree(14);

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
    Tree.push(adu);
  }
  Tree.build();
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
    if (Tree.match(adu) == adu.attr[14])
      cor_num++;
  }
  cout << (double)cor_num / (double)num;

  return 0;
}
