#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

  int n;
  char c;

  vector<vector<char>> 

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