#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[2010];
int d[2010][2010];

int go(int x, int y) {
	if (d[x][y] >= 0) {
		return d[x][y];
	}

	if (x == y) {
		return d[x][y] = 1;
	}
	if (y == x + 1&&a[x]==a[y]) {
		return d[x][y] = 1;
	}

	int check = go(x + 1, y - 1);
	if (a[x] == a[y]&&check) {
		return d[x][y] = 1;
	}
	return d[x][y]=0;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));

	int m;
	cin >> m;
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n",go(x, y));
	}
	return 0;
}