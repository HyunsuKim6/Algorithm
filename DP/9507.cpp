#include <iostream>
#include <algorithm>

using namespace std;

long long d[70];

long long koong(int n) {
	if (d[n]) return d[n];
	return d[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}

int main() {
	int T;
	cin >> T;
	
	d[0] = 1; 
	d[1] = 1;
	d[2] = 2; 
	d[3] = 4;
	
	while (T--) {
		int n;
		cin >> n;
		cout<<koong(n)<<endl;
	}
	
	return 0;
}