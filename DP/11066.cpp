#include <iostream>
#include <cstring>

using namespace std;

int a[510];
int s[510];
int d[510][510];

int go(int i, int j) {
	if (i == j) {
		return 0;
	}

	if (d[i][j] != -1) return d[i][j];

	for (int k = i; k < j; k++) {
		int temp = go(i, k) + go(k + 1, j) + s[j] - s[i - 1];
		if (d[i][j] > temp || d[i][j] == -1) {
			d[i][j] = temp;
		}
	}

	return d[i][j];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}

		memset(d, -1, sizeof(d));

		cout << go(1, n) << endl;
	}
	return 0;
}