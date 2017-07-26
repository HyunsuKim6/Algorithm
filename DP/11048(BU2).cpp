#include <iostream>
#include <algorithm>

using namespace std;

int d[1010][1010];
int a[1010][1010];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (d[i + 1][j] < d[i][j] + a[i + 1][j]) {
				d[i + 1][j] = d[i][j] + a[i + 1][j];
			}
			if (d[i][j + 1] < d[i][j] + a[i][j + 1]) {
				d[i][j + 1] = d[i][j] + a[i][j + 1];
			}
			if (d[i + 1][j + 1] < d[i][j] + a[i + 1][j + 1]) {
				d[i + 1][j + 1] = d[i][j] + a[i + 1][j + 1];
			}
		}
	}

	cout << d[n][m] << endl;
	return 0;
}