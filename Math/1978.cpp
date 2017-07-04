#include <iostream>

using namespace std;

int prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i*i < n; i++) {
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	freopen("Text.txt", "r", stdin);

	int count = 0;
	int T,n;

	cin >> T;

	while (T--) {
		cin >> n;
		if (prime(n)) {
			count++;
		}
	}

	cout << count << endl;
}