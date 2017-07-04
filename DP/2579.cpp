#include <iostream>
#include <algorithm>

using namespace std;

int d[310][3] = { 0 };
int a[310];

int main() {
	freopen("Text.txt", "r", stdin);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0][0] = 0;
	d[0][1] = a[0];
	d[0][2] = a[0];

	for (int i = 1; i < n; i++) {
		d[i][0] = max(d[i - 1][1], d[i - 1][2]);
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	cout << max(d[n - 1][1], d[n - 1][2]) << endl;
	
}