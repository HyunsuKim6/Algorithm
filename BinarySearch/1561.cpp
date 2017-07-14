#include <iostream>

using namespace std;

long long N;
int M;
int a[10010];

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a[i];
	}

	if (N <= M) {
		cout << N << endl;
		return 0;
	}

	long long l = 0;
	long long r = 20000000000000;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long start = 0, end = M;
		for (int i = 0; i < M; i++) {
			end += mid / a[i];
		}

		start = end;

		for (int i = 0; i < M; i++) {
			if (mid%a[i] == 0) {
				start -= 1;
			}
		}

		start += 1;

		if (N < start) {
			r = mid - 1;
		}
		else if (N > end) {
			l = mid + 1;
		}
		else {
			for (int i = 0; i < M; i++) {
				if (mid%a[i] == 0) {
					if (N == start) {
						cout << i + 1 << endl;
						return 0;
					}
					start += 1;
				}
			}
		}
	}
	return 0;
}