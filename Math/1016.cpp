#include <iostream>

using namespace std;

int a[1000010];

int main() {
	long long min, max;
	cin >> min >> max;

	for (int i = 2; i*i <= max; i++) {
		long long start = i*i - min%(i*i);

		if (i*i == min) {
			start = 0;
		}

		for (int j = start; j <= max - min; j += i*i) {
			a[j] = 1;
		}
	}

	int ans = 0;

	for (int i = 0; i <= max - min; i++) {
		if (a[i] == 0) ans++;
	}

	cout << ans << endl;
	return 0;
}