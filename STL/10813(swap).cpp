#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<int> a;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		a.push_back(i + 1);
	}
	
	while (m--) {
		int i, j;
		cin >> i >> j;
		swap(a[i-1], a[j-1]);
	}

	for (auto i : a) {
		cout << i << ' ';
	}
	puts("");
	return 0;
}