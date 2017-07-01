#include <iostream>
#include <algorithm>

using namespace std;

long long a[100010][2];
long long d[100010][3];

int main() {
	freopen("Text.txt", "r", stdin);

	int T,n;

	cin >> T;

	while (T--) {
		cin >> n;

		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				cin >> a[i][j];
			}
		}

		d[0][0] = 0;
		d[0][1] = a[0][1];
		d[0][2] = a[0][0];

		for (int i = 1; i < n; i++) {
			d[i][0] = max(d[i - 1][0],max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][1];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][0];
		}

		cout << max(d[n - 1][0], max(d[n - 1][1], d[n - 1][2])) << endl;

	}
}