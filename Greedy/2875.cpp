#include <iostream>

using namespace std;

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	int Answer = 0;

	while (n >= 2 && m >= 1) {
		n -= 2;
		m -= 1;
		Answer++;
	}

	while (n + m < k) {
		Answer -= 1;
		k -= 3;
	}

	cout << Answer << endl;
}