#include <iostream>

using namespace std;

long long N, M;
long long a[1000010];

bool check(long long m) {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if ((a[i] - m) > 0) {
			ans += (a[i] - m);
		}
		else {
			continue;
		}
	}
	return ans >= M;
}

int main() {
	cin >> N >> M;
	long long max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		if (max < a[i]) {
			max = a[i];
		}
	}

	long long ans = 0;
	long long l = 0;
	long long r = max;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << endl;
	return 0;
}