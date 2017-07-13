#include <iostream>
#include <math.h>

using namespace std;

int solve(int n, int x, int y) {
	if (n == 1) {
		return 2 * x + y;
	}

	if (x < pow(2, n - 1)) {
		if (y < pow(2, n - 1)) {
			return solve(n - 1, x, y);
		}
		else {
			return solve(n - 1, x, y - pow(2, n - 1)) + pow(2, 2 * (n - 1));
		}
	}
	else {
		if (y < pow(2, n - 1)) {
			return solve(n - 1, x- pow(2, n - 1), y ) + 2* pow(2, 2 * (n - 1));
		}
		else {
			return solve(n - 1, x - pow(2, n - 1), y - pow(2, n - 1)) + 3 * pow(2, 2*(n-1));
		}
	}
}

int main() {
	int n, r, c;

	cin >> n >> r >> c;

	cout << solve(n, r, c) << endl;;
}