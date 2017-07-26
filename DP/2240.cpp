#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, w;
int a[1010];
int d[1010][1010];

int go(int i, int m) {
	if (i > t || m > w) return 0;
	if (d[i][m] != -1) return d[i][m];
	int tree = (m % 2 == 0) ? 1 : 2;

	return d[i][m] = max(go(i + 1, m), go(i + 1, m + 1)) + ((a[i] == tree) ? 1 : 0);
}


int main() {
	freopen("Text.txt", "r", stdin);
	cin >> t >> w;

	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));

	printf("%d\n", max(go(1, 0), go(1, 1)));
	return 0;
}