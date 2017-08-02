#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> a[1005];
bool c[1005];
priority_queue<pair<int, int>> q;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}

	c[1] = true;
	for (auto& p:a[1]) {
		q.push(make_pair(-p.second, p.first));
	}

	int ans = 0;

	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		if (c[p.second] == true) {
			continue;
		}
		c[p.second] = true;
		ans += -p.first;
		for (auto& next : a[p.second]) {
			q.push(make_pair(-next.second, next.first));
		}
	}

	cout << ans << endl;

	return 0;
}