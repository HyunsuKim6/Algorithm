#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];
int d[100010][20];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		d[i][0] = a[i];
	}
	for (int j = 1; j < 17; j++) {
		for (int i = 0; i < n; i++) {
			if (i + (1 << j) - 1 < n) {
				d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
			}
			else {
				break;
			}
		}
	}

	while (m--) {
		int start, end;
		scanf("%d %d", &start, &end);
		start--;
		end--;
		int ans = a[start];
		int k = 16;
		while (start <= end && k >= 0) {
			if (start + (1 << k) - 1 <= end) {
				ans = min(ans, d[start][k]);
				start += (1 << k);
			}
			k -= 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}