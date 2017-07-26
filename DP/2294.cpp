#include <iostream>
#include <algorithm>

using namespace std;

int a[110];

int d[10010];

int main() {
	freopen("Text.txt", "r", stdin);
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	fill(d, d + k + 1, -1);

	d[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - a[i] >= 0 && d[j - a[i]] != -1) {
				if (d[j] == -1 || d[j] > d[j - a[i]] + 1) {
					d[j] = d[j - a[i]] + 1;
				}
			}
		}
	}

	cout << d[k] << endl;

	return 0;
}