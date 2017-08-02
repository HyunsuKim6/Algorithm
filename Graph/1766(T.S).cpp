#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int ind[32010];
vector<int> a[32010];
priority_queue<int> q;
int n, m;

void bfs() {
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(-i);
		}
	}
	while (!q.empty()) {
		int now = -q.top();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < a[now].size(); i++) {
			int next = a[now][i];
			ind[next]--;
			if (ind[next] == 0) {
				q.push(-next);
			}
		}
	}

	return;
}

int main() {
	cin >> n >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		ind[y]++;
	}

	bfs();

	return 0;
}