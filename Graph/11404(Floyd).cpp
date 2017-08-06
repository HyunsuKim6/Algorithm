#include <iostream>

using namespace std;

int n,m;
int d[110][110];
int inf = 100000000;

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = inf;
		}
		d[i][i] = 0;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if(d[x][y]>z)d[x][y] = z;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j]>d[i][k]+d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == inf) {
				cout << 0 << ' ';
				continue;
			}
			cout << d[i][j] << ' ';
		}
		puts("");
	}

	return 0;
}