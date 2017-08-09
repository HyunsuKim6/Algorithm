#include <iostream>
#include <queue>

using namespace std;

int a[200][200];
int d[200][200];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}
	}

	deque<pair<int,int>> q;
	long long ans = 0;

	q.push_back(make_pair(0, 0));
	d[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (d[nx][ny] == -1) {
					if (a[nx][ny] == 0) {
						d[nx][ny] = d[x][y];
						q.push_front(make_pair(nx, ny));
					}
					else {
						d[nx][ny] = d[x][y] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}

	cout << d[m - 1][n - 1] << endl;

	return 0;
}