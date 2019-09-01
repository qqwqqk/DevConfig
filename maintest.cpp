#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class people{
public:
  int a,b;
  int rank;
  int pos;
  people(int _a, int _b){
    a=_a; b=_b;
    rank = _b - _a;
    pos = -1;
  }
};

bool sortFun(const people &p1, const people &p2){
  if(p1.rank == p2.rank){
    return p1.a < p2.a;
  } else {
    return p1.rank < p2.rank;
  }
}

int satisfaction(int a,int b, int j, int n){
  int result;
  result = a * (j-1) + b *(n-j);
  return result;
}

int main(){

  int n,a,b;

  vector<people> lists;

  cin>>n;
  for(int i=0; i<n;i++){
    cin >> a >> b;

    people item(a,b);
    lists.push_back(item);
  }

  sort(lists.begin(), lists.end(), sortFun);

  int result = 0;
  int temp = 0;
  for(int i=0; i<n; i++){
    temp = satisfaction(lists[i].a, lists[i].b, i+1, n);
    result += temp;
  }

  cout<< result <<endl;

	return 0;
}