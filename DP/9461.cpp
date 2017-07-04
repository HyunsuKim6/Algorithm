#include <iostream>
#include <algorithm>

using namespace std;

int d[110] = { 0 };

int main() {
	//freopen("Text.txt", "r", stdin);

	int T,n;

	cin >> T;

	for (int i = 0; i < 3; i++) {
		d[i] = 1;
	}
	
	for (int i = 3; i < 5; i++) {
		d[i] = 2;
	}

	while (T--) {
		cin >> n;

		for (int i = 5; i < n; i++) {
			d[i] = d[i - 1] + d[i - 5];
		}

		cout << d[n - 1] << endl;
	}
	
}