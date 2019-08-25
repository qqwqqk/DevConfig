#include "../header/filehandle.h"
#include <fstream>
#include <cstdlib>
using namespace std;

void deltag(string net, string inte, int num, string type){
  const char dilem = ',';
  const char split = ' ';
  const string readpath = "dataset/netdata/Metadata_" + net + "_Single" + type + "_" + inte + to_string(num) + "CS.txt";
  const string writepath = "dataset/outdata/Edgelist_" + net  + "_" + type + "_" + inte + to_string(num) + ".txt";

  ifstream infile;
  ofstream outfile;
  string line;
  infile.open(readpath, ios::in);
  outfile.open(writepath, ios::out);

  if(!infile){ cout<< "file open error:\t" << readpath <<endl; exit(0); } 

    while(!infile.eof()){
    getline(infile, line);
    int linePos = 0;
    int lineSize = 0;
    string cache;
    vector<int> array;

    for(int i = 0 ; i < line.size(); i++){
      if(line[i] == dilem){
        lineSize = i - linePos;
        cache = line.substr(linePos, lineSize);
        array.push_back(stoi(cache));
        linePos = i+1;
      }
    }
    cache = line.substr(linePos, line.size() - linePos);
    if(cache.size()>0){ array.push_back(stoi(cache)); }

    //记录两人种类型节点数量并将解析的内容写入边对象缓存
    if(array.size() > 2){
      outfile << array[1] << split << array[2] << '\n';
    }
  }

  infile.close();
  outfile.close();

}
