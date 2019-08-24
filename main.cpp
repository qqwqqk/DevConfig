#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int n){
	int stop = n / 6 + 1, Tstop = sqrt(n) + 5;
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1) {
		return false;
	}
	for (unsigned long long i = 1; i <= stop; i++) {
		if (i * 6 >= Tstop) { break; }
		if ((n % (i * 6 + 1) == 0) || (n % (i * 6 + 5) == 0)) {
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	int count = 0;

	while (1){
		cout << "\nbegin:" << endl;
		count = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			if (is_prime(i)){ count++; }
		}
		cout << n - count - 1 << endl;
	}
	return 0;
}