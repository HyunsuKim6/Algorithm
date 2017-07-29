#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[55];
int d[55][250010];
int n;
int min_h = -1000000;

int go(int num, int height) {
	if (height > 250000) return min_h;

	if (num > n) {
		if (height == 0) {
			return 0;
		}
		else {
			return min_h;
		}
	}

	int& ans = d[num][height];

	if (ans != -1) return ans;

	ans = go(num + 1, height);
	ans = max(ans, go(num + 1, height + a[num]));
	if (height >= a[num]) {
		ans = max(ans, go(num + 1, height - a[num]) + a[num]);
	}
	else {
		ans = max(ans, go(num + 1, a[num] - height) + height);
	}

	return ans;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));

	cout<<go(1, 0)<<endl;


	return 0;
}