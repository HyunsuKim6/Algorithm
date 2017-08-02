#include <iostream>
#include <vector>

using namespace std;

int a[1010][1010];
int inf = 1000000000;
int d[1010];
bool check[1010];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = inf;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (a[x][y] > z) a[x][y] = z;
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	d[start] = 0;

	for (int i = 0; i < n; i++) {
		int x, dist = inf + 1;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && dist > d[j]) {
				x = j;
				dist = d[j];
			}
		}
		check[x] = true;
		for (int j = 1; j <= n; j++) {
			if (d[j] > dist + a[x][j]) {
				d[j] = dist + a[x][j];
			}
		}
	}

	cout << d[end] << endl;

	return 0;
}