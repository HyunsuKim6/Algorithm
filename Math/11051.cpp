#include <iostream>

using namespace std;

int d[1001][1001];
int mod = 10007;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			d[i][j] %= mod;
		}
	}

	cout << d[n][k] << endl;

	return 0;
}