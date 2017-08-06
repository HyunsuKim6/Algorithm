#include <iostream>

using namespace std;

int d[410][410];
int inf = 100000000;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = inf;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		d[x][y] = z;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	int ans = inf;

	for (int i = 1; i <= n; i++) {
		if (ans > d[i][i])ans = d[i][i];
	}

	if (ans == inf)cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}