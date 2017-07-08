#include <iostream>
#include <algorithm>

using namespace std;

int a[51][51];
int Answer[10000];
int n=1,m=1, cnt = 0;

int u[8] = { 1,-1,0,0, 1, 1, -1, -1 };
int r[8] = { 0,0,1,-1, 1, -1, 1, -1 };


void dfs(int i, int j) {
	cnt++;
	a[i][j] = 0;
	for (int k = 0; k < 8; k++) {
		int x = i + u[k];
		int y = j + r[k];
		if (x >= 0 && x < m&&y >= 0 && y < n&&a[x][y] == 1) {
			dfs(x, y);
		}
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);

	while (1) {
		int k = 0;

		cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &a[i][j]);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) {
					dfs(i, j);
					k++;

				}
			}
		}

		cout << k << endl;
	}
}