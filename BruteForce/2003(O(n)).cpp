#include <iostream>

using namespace std;

int a[10010];

int main() {
	int n, m, ans = 0, l = 0, r = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = a[0];

	while (l <= r && r < n) {
		if (sum < m) {
			r++;
			sum += a[r];
		}
		else if (sum == m) {
			ans++;
			r++;
			sum += a[r];
		}
		else if (sum > m) {
			sum -= a[l];
			l++;
		}
	}

	cout << ans << endl;

	return 0;
}