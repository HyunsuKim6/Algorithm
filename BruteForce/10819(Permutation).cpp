#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int n;
	int ans = 0,result = 0;

	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	do {
		result = 0;
		for (int i = 0; i < n - 1; i++) {
			result += abs(a[i] - a[i + 1]);
		}

		if (ans < result) {
			ans = result;
		}
	} while (next_permutation(a.begin(), a.end()));

	cout << ans << endl;
}