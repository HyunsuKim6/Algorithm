#include <iostream>
#include <algorithm>

using namespace std;

int d[101] = { 0 };

int main() {
	int T;
	cin >> T;
	while (T--) {
		fill(d, d + 100, 0);
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int j = 1;
			while (j*i <= n) {
				d[i*j] ^= 1;
				j++;
			}
		}

		for (int i = 1; i <= n; i++) {
			ans += d[i];
		}
		cout << ans << endl;
	}
	return 0;
}