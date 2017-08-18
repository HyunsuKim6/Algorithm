#include <iostream>

using namespace std;

long long s[100010];
int a[100010];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}

	while (m--) {
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%lld\n", s[j] - s[i - 1]);
	}

	return 0;
}