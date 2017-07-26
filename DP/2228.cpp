#include <iostream>
#include <cstring>

using namespace std;

int a[101];
int s[101];
int d[101][101];
int min = -32768 * 101;

int go(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return min;
	if (d[n][m] != -1) return d[n][m];

	int& ans = d[n][m];
	ans = go(n - 1, m);
	for (int i = 1; i <= n; i++) {
		int temp = go(i - 2, m - 1) + s[n] - s[i - 1];
		if (ans < temp) ans = temp;
	}

	return ans;
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	memset(d, -1, sizeof(d));

	cout<<go(n, m)<<endl;

	return 0;
}