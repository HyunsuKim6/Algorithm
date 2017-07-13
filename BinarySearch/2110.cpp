#include <iostream>
#include <algorithm>

using namespace std;

int N, C;

long long a[200010];

bool check(int m) {
	int answer = 1;
	int check = a[0]+m;
	for (int i = 1; i < N; i++) {
		if (check <= a[i]) {
			check = a[i]+m;
			answer += 1;
		}
	}

	return answer >= C;
}

int main() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	long long ans = 0;
	long long l = 0;
	long long r = a[N - 1] - a[0];

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
}