#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a;

	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}

	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		rotate(a.begin() + (i-1), a.begin() + (k-1), a.begin() + j);
	}

	for (auto i : a) {
		cout << i << ' ';
	}
	puts("");
	return 0;
}