#include <iostream>

using namespace std;

int a[10010];

int main() {
	int ans = 0;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = i; j < n; j++) {
			num += a[j];
			if (num == m) {
				ans++;
				break;
			}
			if (num > m) {
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}