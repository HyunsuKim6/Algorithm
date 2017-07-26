#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int d[1010][1010];
int a[1010][1010];

int go(int n, int m) {
	if (n == 1 && m == 1) return a[1][1];
	if (n <= 0 || m <= 0) return 0;
	if (d[n][m] >= 0) {
		return d[n][m];
	}

	d[n][m] = go(n - 1, m) + a[n][m];
	int temp = go(n, m - 1) + a[n][m];
	if (d[n][m] < temp) {
		d[n][m] = temp;
	}

	return d[n][m];
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	memset(d, -1, sizeof(d));

	cout << go(n, m) << endl;

	return 0;
}