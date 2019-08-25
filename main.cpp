#include "header/filehandle.h"
#include "header/test.h"
#include <stdlib.h>
using namespace std;

int main(){
  //文件处理
  string net = "WR";
  string inte = "E";
  int num = 10000;
  string type = "A";
  deltag(net, inte, num, type);

  cout<<"init network: " << net << type << inte << num  <<endl;
}