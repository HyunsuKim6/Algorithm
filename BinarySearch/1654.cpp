#include <iostream>

using namespace std;

int a[10010];
int K, N;

int check(int m) {
	long long Answer = 0;

	for (int i = 0; i < K; i++) {
		Answer += a[i] / m;
	}

	if (Answer >= N) {
		return true;
	}
	
	return false;
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> K >> N;

	int max = 0;

	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
		if (max < a[i]) {
			max = a[i];
		}
	}

	int l = 0;
	int r = max;

	long long mid = 0;
	long long ans = 0;

	while (l <= r) {
		mid = (l + r) / 2;

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