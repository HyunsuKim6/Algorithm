#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a[5000100];

int main() {
	int n,l;
	cin >> n >> l;
	deque<pair<int, int>> d;
	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		int cur = a[i];
		if (!d.empty() && d.front().second <= i - l) {
			d.pop_front();
		}
		while (!d.empty() && d.back().first > cur) {
			d.pop_back();
		}
		d.push_back(make_pair(cur, i));
		ans[i] = d.front().first;
	}

	for (int p : ans) {
		printf("%d ", p);
	}

	puts("");

	return 0;
}