#include <iostream>
#include <math.h>

using namespace std;

void solve(int n, int x, int y) {
	if (n == 0) {
		return;
	}
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}

int main() {
	int n;

	cin >> n;

	int cnt = pow(2, n) - 1;

	cout << cnt << endl;

	solve(n, 1, 3);
}