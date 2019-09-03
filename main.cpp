#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class treasure{
public:
	int x, h;
	int rank;
	treasure(int _x = -1, int _h = -1){
		x = _x; h = _h;
		rank = _x > _h ? _x : _h;
	};
};

bool sortFun(const treasure &p1, const treasure &p2){
  if(p1.rank == p2.rank){
    if(p1.x == p2.x){
      return p1.h < p2.h;
    }
    return p1.x < p2.x;
  }
	return p1.rank < p2.rank;
}

int main(){
	int n, x, h;
	vector<treasure> lists;
	cin >> n;

	for (int i=0; i<n; i++){
		cin >> x >> h;
		treasure item(x, h);
		lists.push_back(item);
	}

	sort(lists.begin(), lists.end(), sortFun);

	int rank = 0;
	int count = 0;
	for (vector<treasure>::iterator iter = lists.begin(); iter != lists.end(); iter++){
		if (iter->x >= rank && iter->h >= rank){ 
			count++; 
			rank = iter->rank; 
		}
	}

	cout << count << endl;

	return 0;
}