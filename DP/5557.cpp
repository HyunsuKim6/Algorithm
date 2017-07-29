#include <iostream>

using namespace std;

long long d[110][22];
int a[110];

int main() {
	freopen("Text.txt", "r", stdin);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0][a[0]] = 1;

	for (int i = 0; i < n - 2; i++) {
		for (int k = 0; k <= 20; k++) {
			if (d[i][k] > 0) {
				if (k + a[i + 1] <= 20) {
					d[i + 1][k + a[i + 1]] += d[i][k];
				}
				if (k - a[i + 1] >= 0) {
					d[i + 1][k - a[i + 1]] += d[i][k];
				}
			}
		}
	}

	cout << d[n - 2][a[n - 1]] << endl;
	return 0;
}