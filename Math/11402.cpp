#include <iostream>
#include <vector>

using namespace std;

int d[2001][2001];
vector<int> a;
vector<int> b;

int main() {
	int n, k, m;
	cin >> n >> k >> m;

	for (int i = 0; i <= m; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j <= i-1; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			d[i][j] % m;
		}
	}

	while (n > 0 || k > 0) {
		a.push_back(n%m);
		b.push_back(k%m);
		n /= m;
		k /= m;
	}

	int ans = 1;

	for (int i = 0; i < a.size(); i++) {
		ans *= d[a[i]][b[i]];
		ans %= m;
	}

	cout << ans << endl;

	return 0;
}