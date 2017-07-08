#include <iostream>
#include <queue>

using namespace std;

int a[1005][1005];
int d[1005][1005];
int M, N;
int count = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					a[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	int Answer = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
			if (a[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 0 && d[i][j] == -1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
				if(Answer < d[i][j]){
					Answer = d[i][j];
			}
		}
	}

	cout << Answer << endl;

	return 0;
}