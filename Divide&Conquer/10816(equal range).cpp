#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	int m; cin >> m;

	while (m--) {
		int y;
		scanf("%d", &y);
		auto p = equal_range(a.begin(), a.end(), y);
		printf("%d ", p.second - p.first);
	}
	puts("");
	return 0;
}