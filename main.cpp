#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>;
using namespace std;

int main(){

	map<char, int> lists;
	string str;
	cin >> str;

	int max = 0;
	int n = str.length();
	for (int i = 0; i < n; i++){
		char temp = str[i];
		map<char, int>::iterator item = lists.find(temp);
		if (item == lists.end()){
			int count = 1;
			max = max > count ? max : count;
			lists.insert(pair<char, int>(temp, 1));
		}
		else {
			int count = item->second + 1;
			max = max > count ? max : count;
			item->second = count;
		}
	}

	cout << max << endl;

	return 0;
}