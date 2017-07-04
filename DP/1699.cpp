#include <iostream>
#include <algorithm>

using namespace std;

int d[100010];

int main() {
	//freopen("Text.txt", "r", stdin);

	int n;

	cin >> n;

	for (int i = 0; i <=n; i++) {
		d[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			d[i] = min(d[i], d[i - j*j] + 1);
		}
	}
	
	cout << d[n] << endl;
}