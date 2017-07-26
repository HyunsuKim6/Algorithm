#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;
string a;
int d[2510][2510];
int g[2510];

int go(int x, int y) {
	if (x == y) {
		return 1;
	}
	else if (x + 1 == y) {
		if (a[x] == a[y])return 1;
		else return 0;
	}

	if (d[x][y] >= 0) return d[x][y];
	if (a[x] != a[y]) return d[x][y] = 0;
	else return d[x][y] = go(x + 1, y - 1);
}

int main() {
	cin >> a;

	memset(d, -1, sizeof(d));

	int n = a.length();

	a = " " + a;

	g[0] = 0;
	for (int i = 1; i <= n; i++) {
		g[i] = -1;
		for (int j = 1; j <= i; j++) {
			if (go(j, i)) {
				if (g[i] == -1 || g[i] > g[j - 1] + 1) {
					g[i] = g[j - 1] + 1;
				}
			}
		}
	}

	cout << g[n] << endl;
	return 0;
}