#include <iostream>
#include <vector>

using namespace std;

int n,m;
int d[110][110];
int to[110][110];
int inf = 100000000;

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = inf;
			to[i][j] = j;
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
					to[i][j] = to[i][k];
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == inf || i == j) {
				puts("0");
				continue;
			}
			vector<int> v;
			v.push_back(i);
			for (int k = i; k != j;) {
				v.push_back(k = to[k][j]);
			}
			cout << v.size()<<' ';
			for (auto k : v) {
				cout << k << ' ';
			}
			puts("");
		}
	}

	return 0;
}