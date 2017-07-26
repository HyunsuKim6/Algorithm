#include <iostream>
#include <cstring>

using namespace std;

int a[510][2];
int d[510][510];

int go(int i, int j) {
	if (d[i][j] != -1) return d[i][j];
	if (i == j) return 0;
	if (i + 1 == j) {
		return d[i][j] = a[i][0] * a[j][0] * a[j][1];
	}
	for (int k = i; k < j; k++) {
		if (d[i][j] == -1 || d[i][j] > go(i, k) + go(k + 1, j) + a[i][0] * a[k][1] * a[j][1]) {
			d[i][j] = go(i, k) + go(k + 1, j) + a[i][0] * a[k][1] * a[j][1];
		}
	}
	return d[i][j];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1]; 
	}

	memset(d, -1, sizeof(d));

	cout<<go(0, n - 1)<<endl;
	return 0;
}