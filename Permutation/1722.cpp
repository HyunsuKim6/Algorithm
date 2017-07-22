#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, what;

	cin >> N >> what;

	vector<int> a(N);
	int c[50] = { 0 };
	long long f[30] = { 1 };

	for (int i = 1; i < 21; i++) {
		f[i] = f[i - 1] * i;
	}


	if (what == 2) {
		long long ans = 1;

		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < a[i]; j++) {
				if (c[j] == 0) {
					ans += f[N - i - 1];
				}
			}
			c[a[i]] = 1;
		}

		cout << ans << endl;
	}
	else {
		long long k;

		cin >> k;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (c[j] == 0) {
					if (k - f[N - i - 1] <= 0) {
						c[j] = 1;
						a[i] = j;
						break;
					}

					else {
						k -= f[N - i - 1];
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			cout << a[i] << ' ';
		}
		puts("");
	}
}