#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <vector>;
using namespace std;

int main(){

  int n,m;
  cin>>n>>m;

  int box_1 = 0;
  int box_2 = 0;
  int key_1 = 0;
  int key_2 = 0;

  int temp;

  for(int i=0; i<n; i++){
    cin >> temp;
    if(temp % 2 == 1){box_1++;} else {box_2++;}
  }

  for(int i=0; i<m; i++){
    cin >> temp;
    if(temp % 2 == 1){key_1++;} else {key_2++;}
  }

  int open_1 = key_1 < box_1 ? key_1 : box_1;
  int open_2 = key_2 < box_2 ? key_2 : box_2;

  int result = open_1+open_2;
  cout<<result<<endl;

	return 0;
}