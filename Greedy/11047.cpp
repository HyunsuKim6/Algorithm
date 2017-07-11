#include <iostream>

using namespace std;

int a[20];

int main() {
	long long n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int cnt = 0;

	for (int i = n - 1; i >= 0; i--) {
		while (m - a[i] >= 0) {
			m -= a[i];
			cnt++;
		}
	}

	cout << cnt << endl;
}