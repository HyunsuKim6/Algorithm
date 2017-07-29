#include <iostream>

using namespace std;

int d[110][1010];
int a[110];

int main() {
	int N, S, M;

	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	d[0][S] = 1;

	for (int i = 0; i < N; i++) {
		for (int k = 0; k <= 1000; k++) {
			if (d[i][k] == 1) {
				if (k + a[i + 1] <= M) {
					d[i + 1][k + a[i + 1]] = 1;
				}
				if (k - a[i + 1] >= 0) {
					d[i + 1][k - a[i + 1]] = 1;
				}
			}
		}
	}

	int ans = -1;

	for (int k = 0; k <= 1000; k++) {
		if (d[N][k]==1) {
			if (ans < k) {
				ans = k;
			}
		}
	}

	cout << ans << endl;

	return 0;
}