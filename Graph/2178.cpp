#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;

int a[110][110];
int d[110][110];
int check[110][110] = { 0 };
int n, m;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs() {
	q.push(make_pair(0, 0));
	check[0][0] = true;
	d[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == 0 && a[nx][ny]==1) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;
					check[nx][ny] = 1;
				}
			}
		}
	}
	
}

int main() {
	//freopen("Text.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	bfs();

	cout << d[n - 1][m - 1] << endl;

}