#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int a[100010];
int group[10010];
int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int r = sqrt(n);

	for (int i = 0; i < n; i++) {
		if (i%r == 0) {
			group[i / r] = a[i];
		}
		else {
			group[i / r] = min(group[i / r], a[i]);
		}
	}

	while (m--) {
		int ans = 1000000010;
		int start, end;
		scanf("%d %d", &start, &end);

		start--;
		end--;

		if ((start / r) == (end / r)) {
			for (int i = start; i <= end; i++) {
				ans = min(ans, a[i]);
			}
			printf("%d\n", ans);
			continue;
		}

		while (true) {
			ans = min(ans, a[start]);
			start += 1;
			if (start % r == 0) {
				break;
			}
		}

		while (true) {
			ans = min(ans, a[end]);
			end -= 1;
			if (end%r == r - 1) {
				break;
			}
		}

		for (int i = start / r; i <= end / r; i++) {
			ans = min(ans, group[i]);
		}
		
		printf("%d\n", ans);
	}
	return 0;
}