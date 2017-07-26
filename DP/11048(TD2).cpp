#include <iostream>
#include <cstring>

using namespace std;

int a[1010][1010];
int d[1010][1010];
int n, m;

int go(int x, int y) {
	if (x == n&&y == m) {
		return a[n][m];
	}
	if (x > n || y > m) {
		return 0;
	}
	if (d[x][y] >= 0) {
		return d[x][y];
	}
	d[x][y] = go(x + 1, y) + a[x][y];
	int temp = go(x, y + 1) + a[x][y];
	if (d[x][y] < temp) {
		d[x][y] = temp;
	}
	return d[x][y];
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	memset(d, -1, sizeof(d));

	cout << go(1, 1) << endl;
	return 0;
}