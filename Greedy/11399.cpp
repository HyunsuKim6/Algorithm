#include <iostream>
#include <algorithm>

using namespace std;

int a[1002];
int d[1002] = { 0 };

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int Answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			d[i] += a[j];
		}
	}

	for (int i = 0; i < n; i++) {
		Answer += d[i];
	}

	cout << Answer << endl;
}