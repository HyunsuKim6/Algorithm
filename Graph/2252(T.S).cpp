#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int indeg[32010];
vector<int> a[32001];
queue<int> q;

void bfs() {
	for (int i = 1; i <= n; i++) {
		if(indeg[i]==0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < a[now].size(); i++) {
			int next = a[now][i];
			indeg[next]--;
			if (indeg[next] == 0) {
				q.push(next);
			}
		}
	}
	return;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		indeg[y]++;
	}

	bfs();

	return 0;
}