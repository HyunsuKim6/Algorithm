#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int to, int cost) :to(to), cost(cost) {
	}
};

vector<Edge> a[40010];
queue<int> q;

bool check[40010];
int depth[40010];
int parent[40010];
int cost[40010];

int LCA(int x, int y) {
	int ans = 0;
	if (depth[x] < depth[y]) {
		swap(x, y);
	}
	while (depth[x] != depth[y]) {
		ans += cost[x];
		x = parent[x];
	}
	while (x!=y) {
		ans += cost[x];
		ans += cost[y];
		x = parent[x];
		y = parent[y];
	}

	return ans;
}

int main() {
	freopen("Text.txt", "r", stdin);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		a[u].push_back(Edge(v, t));
		a[v].push_back(Edge(u, t));
	}

	check[1] = true;
	depth[1] = 0;
	parent[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++){
			Edge& e = a[x][i];
			int y = e.to;
			if (check[y] == false) {
				check[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				cost[y] = e.cost;
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