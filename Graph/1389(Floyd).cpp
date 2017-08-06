#include <iostream>

using namespace std;

int d[110][110];
int inf = 100000000;

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = inf;
		}
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		d[x][y] = 1;
		d[y][x] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int ans = inf;
	int num;

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp += d[i][j];
		}
		if (ans > temp) {
			ans = temp;
			num = i;
		}
	}

	cout << num << endl;

	return 0;
}