#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <vector>;
using namespace std;

class company{
public:
	int code;
	vector<int> price;
	company(int _code, int _price){
		code = _code;
		price.push_back(_price);
	};
};

map<int, int> getresult(set<int> xlist, map<int, company> lists){
	int company_id, company_price;

	int max = 0;
	if (lists.size() > 0){
		for (map<int, company>::iterator iter = lists.begin(); iter != lists.end(); iter++){
			int val = iter->second.price.back();
			if (max <= val && xlist.count(iter->first) < 1){ 
				max = val; 
				company_id = iter->first;
				company_price = val;
			}
		}
	}

	map<int, int> res;
	res.insert(pair<int, int>(company_id, company_price));
	return res;
};

int main(){

	int n, q;
	map<int, company> lists;

	cin >> n;
	int num = 0, price = 0;

	for (int i = 0; i<n; i++){
		cin >> num >> price;
		map<int, company>::iterator iter = lists.find(num);
		if (iter == lists.end()){
			company val(num, price);
		}
		else {
			iter->second.price.push_back(price);
		}
	}

	cin >> q;
	int leng = 0;
	set<int> xlist;
	int max = 0;
	for (int i = 0; i<n; i++){
		cin >> leng;
		for (int i = 0; i<leng; i++){
			cin >> num;
			xlist.insert(num);
		}

		map<int, int> result = getresult(xlist, lists);
		map<int, int>::iterator temp = result.begin();
		cout << temp->first << ' ' << temp->second << endl;
	}

	return 0;
}