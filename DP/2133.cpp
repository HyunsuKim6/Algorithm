#include <iostream>
#include <algorithm>

using namespace std;

int d[35] = { 0 };

int main() {
	//freopen("Text.txt", "r", stdin);

	int n;

	cin >> n;

	d[0] = 1;

	for (int i = 2; i <= n; i+=2) {
		for (int j = 2; j <= i; j+=2) {
			if (j == 2) {
				d[i] += 3 * d[i - j];
			}
			else {
				d[i] += 2 * d[i - j];
			}
		}
	}

	cout << d[n] << endl;

	
}