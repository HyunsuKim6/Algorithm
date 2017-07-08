#include <iostream>

using namespace std;

int a[30][30];
int Answer[10000];
int n, cnt = 0;

int u[4] = { 1,-1,0,0 };
int r[4] = { 0,0,1,-1 };


void dfs(int i, int j) {
	cnt++;
	a[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		int x = i + u[k];
		int y = j + r[k];
		if (x >= 0 && x < n&&y >= 0 && y < n&&a[x][y] == 1) {
			dfs(x, y);
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);

	int k = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				dfs(i, j);
				Answer[k] = cnt;
				k++;
				cnt = 0;
			}
		}
	}

	cout << k << endl;
	
	for (int i = 0; i < k; i++) {
		cout << Answer[i] << endl;
	}

}