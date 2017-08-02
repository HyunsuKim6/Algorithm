#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[10010];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int time;
		cin >> time;
		int k; cin >> k;
		int mx = 0;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			mx = max(mx, d[x]);
		}
		
		d[i] = mx + time;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
	}

	cout << ans << endl;

	return 0;
}