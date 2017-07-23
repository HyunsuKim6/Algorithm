#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);

	while (m--) {
		int i, j, num;
		cin >> i >> j >> num;

		fill(a.begin() + (i - 1), a.begin() + j, num);
	}

	for (auto i : a) {
		cout << i << ' ';
	}
	puts("");

	return 0;
}