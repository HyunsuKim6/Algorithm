#include <iostream>
#include <vector>

using namespace std;

int n, b;

vector<vector<int>> calc(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= 1000;
			}
		}
	}

	return ans;
}

int main() {
	cin >> n >> b;

	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) {
			ans = calc(ans, a);
		}
		a = calc(a, a);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}