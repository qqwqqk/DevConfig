#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Name{
public:
	string _str1, _str2;
	Name(string str1, string str2){
		_str1 = str1; _str2 = str2;
	}
};

set<string> getName(map<string, int> names){
	set<string> res;
	int max = 0;
	for (map<string, int>::iterator iter = names.begin(); iter != names.end(); iter++){
		if (iter->second > max){
			res.clear();
			res.insert(iter->first);
		}
		if (iter->second == max){
			res.insert(iter->first);
		}
	}
	if (max == 0){ res.clear(); }
	return res;
}


int main(){
	map<string, int> names;
	vector<Name> lists;
	set<string> res;
	string str1, str2;
	while (cin >> str1 >> str2){
		cout << '\t' << '\t' << str1 << str2 << endl;
		Name item(str1,str2);
		lists.push_back(item);
		map<string, int>::iterator iter = names.find(str1);
		if ( iter != names.end()){ names.insert(pair<string, int>(str1, 1)); }
		else { iter->second += 1; }
	}

	while (1){
		res = getName(names);
		if (res.size() < 1){ break; }
		for (int i = 0; i < lists.size(); i++){
			if (res.count(lists[i]._str1)>0){
				cout << lists[i]._str1 << " " << lists[i]._str2 << endl;
			}
		}
		for (set<string>::iterator val = res.begin(); val != res.end(); val++){
			names.find(*val)->second = 0;
		}
	}

	cout << "end" << endl;

	return 0;
}