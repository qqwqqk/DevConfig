#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(){
  string str;
  cin>>str;

  bool tag = true;
  int count = str.size();
  for(int i=0; i<str.size(); i++){
    if(str[i]>94 && tag==false){
      if( i+1 < str.size()-1){
        if(str[i+1] < 94){
          tag = !tag;
          count++;
        }
      } else {
        count++;
      }
    }

    if(str[i]<94 && tag==true){
      if( i+1 < str.size()-1){
        if(str[i+1] > 94){
          tag = !tag;
          count++;
        }
      } else {
        count++;
      }
    }
  }
  
  cout<<count;
  return 0;
}