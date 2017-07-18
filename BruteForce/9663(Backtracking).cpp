#include <iostream>

using namespace std;

int n, ans = 0;

int chess[20][20] = { 0 };

bool check(int row, int col) {
	for (int i = 0; i < n; i++) {
		if (i == row) {
			continue;
		}
		if (chess[i][col] == 1) {
			return false;
		}
	}

	int x = row-1; int y = col+1;
	while (x >= 0 && y < n) {
		if (chess[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}

	x = row-1; y = col-1;
	while (x >= 0 && y >= 0) {
		if (chess[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}
	return true;
}

void go(int row) {
	if (row == n) {
		ans++;
	}
	for (int col = 0; col < n; col++) {
		chess[row][col] = 1;
		if (check(row, col)) {
			go(row + 1);
		}
		chess[row][col] = 0;
	}
}

int main() {
	cin >> n;

	go(0);

	cout << ans << endl;
}