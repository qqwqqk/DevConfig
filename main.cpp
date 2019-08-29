#include <iostream>
#include <set>
#include <vector>;
using namespace std;

int main(){
	
	int n = 0;
	int max = 0;
	set<char> pass;
	vector<int> nums;
	vector<char> tags = {'A','B','C','D','E','F','G','H','I','J','K','L','M'};

	cin >> n;
	for (int i = 0; i < n; i++){
		char temp;
		cin >> temp;
		pass.insert(temp);
	}
	for (int i = 0; i < 13; i++){
		int temp;
		cin >> temp;
		nums.push_back(temp);
		max = max > temp ? max : temp;
	}

	for (int i = 0; i < 13; i++){
		if (nums[i] == max){
			cout << tags[i] << endl;
			break;
		}
	}

	return 0;
}