#include <iostream>

using namespace std;

int n, ans = 0;

int chess[20][20] = { 0 };
int colc[20] = { 0 };
int ldiag[50] = { 0 };
int rdiag[50] = { 0 };

bool check(int row, int col) {
	if (colc[col] == 1) {
		return false;
	}
	if (ldiag[col - row + n] == 1) {
		return false;
	}
	if (rdiag[col + row] == 1) {
		return false;
	}
	return true;
}

void go(int row) {
	if (row == n) {
		ans++;
	}
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			chess[row][col] = 1;
			colc[col] = 1;
			ldiag[col - row + n] = 1;
			rdiag[col + row] = 1;

			go(row + 1);

			chess[row][col] = 0;
			colc[col] = 0;
			ldiag[col - row + n] = 0;
			rdiag[col + row] = 0;
		}
	}
}

int main() {
	cin >> n;

	go(0);

	cout << ans << endl;
	
	return 0;
}