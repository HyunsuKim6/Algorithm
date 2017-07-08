#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
int N;
int a[101][101];
int d[101][101];
int g[101][101] = { 0 };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 1&& g[i][j]==0) {
				cnt++;
				q.push(make_pair(i, j));
				g[i][j] = cnt;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							if (a[nx][ny] == 1 && g[nx][ny] == 0) {
								g[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					g[nx][ny] = g[x][y];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int Answer = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < N && y >= 0 && y < N) {
					if (g[i][j] != g[x][y]) {
						if (Answer == -1 || Answer > d[i][j] + d[x][y]) {
							Answer = d[i][j] + d[x][y];
						}
					}
				}
			}
		}
	}

	cout << Answer << endl;
	return 0;
}