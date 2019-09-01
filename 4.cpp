#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <vector>;
using namespace std;

class people{
public:
  int a,b;
  int rank;
  int pos;
}

int satisfaction(int a,int b, int j, int n){
  int result;
  result = a * (j-1) + b *(n-j);
  return result;
}

int main(){

  int n,m;
  cin>>n>>m;



	return 0;
}