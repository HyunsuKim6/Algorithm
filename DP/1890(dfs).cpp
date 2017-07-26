#include <iostream>

using namespace std;

int a[110][110];
long long d[110][110];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int n;

long long dfs(int x, int y) {
	if (x == n - 1 && y == n - 1) return 1;
	if (d[x][y]) return d[x][y];
	if (a[x][y] == 0) return 0;
	
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i] * a[x][y];
		int ny = y + dy[i] * a[x][y];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			d[x][y]+=dfs(nx, ny);
		}
	}
	return d[x][y];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	dfs(0, 0);

	cout << d[0][0] << endl;
	return 0;
}