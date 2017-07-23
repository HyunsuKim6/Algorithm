#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> a;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		a.push_back(i + 1);
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		reverse(a.begin() + (i - 1), a.begin() + j);
	}

	for (auto i : a) {
		cout << i << ' ';
	}

	puts("");
	return 0;	
}