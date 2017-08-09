#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[50010];
int depth[50010];
bool check[50010];
int parent[50010];

int LCA(int x, int y) {
	if (depth[x] < depth[y]) {
		swap(x, y);
	}
	while (depth[x] != depth[y]) {
		x = parent[x];
	}
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}

	return x;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int v, u;
		cin >> v >> u;

		a[u].push_back(v);
		a[v].push_back(u);
	}

	parent[1] = 0;
	depth[1] = 0;
	check[1] = true;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
			if (check[y] == false) {
				parent[y] = x;
				depth[y] = depth[x] + 1;
				check[y] = true;
				q.push(y);
			}
		}
	}

	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << endl;
	}

	return 0;
}