#include <iostream>

using namespace std;

int a[1000100];
int s[1000100];
int cnt[1000100];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	 }

	for (int i = 1; i <= n; i++) {
		s[i] = (s[i - 1] + a[i])%m;
	}

	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		cnt[(s[i] % m)]++;
	}

	long long ans = 0;

	for (int i = 0; i < m; i++) {
		ans += ((long long)cnt[i] * (long long)(cnt[i] - 1)) / 2LL;
	}

	printf("%lld\n", ans);

	return 0;
}