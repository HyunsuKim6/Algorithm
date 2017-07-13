#include <iostream>

using namespace std;

int a[100][100];

bool cmp(int x ,int y ,int size) {
	int num = a[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if(num!=a[i][j]) return false;
		}
	}

	return true;
}

void solve(int x,int y, int size) {
	if (cmp(x, y, size)) {
		cout << a[x][y];
		return;
	}
	cout << '(';
	int m = size / 2;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(x + i*m,y + j*m, m);
		}
	}
	cout << ')';
}

int main() {
	freopen("Text.txt", "r", stdin);
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	solve(0, 0, n);
}