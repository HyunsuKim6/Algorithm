#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool c[1005];
vector<pair<int,int>> a[1005];

struct Edge {
	int start, end, cost;
	Edge() :start(0),end(0),cost(0){
	}
	Edge(int start,int end,int cost) :start(start), end(end), cost(cost) {
	}
	bool operator < (const Edge & other) const {
		return cost > other.cost;
	}
};

priority_queue<Edge> q;

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
	for (int i = 0; i < a[1].size(); i++) {
		q.push(Edge(1, a[1][i].first, a[1][i].second));
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		Edge e;
		while (!q.empty()) {
			e = q.top();
			q.pop();
			if (c[e.end] == false) {
				break;
			}
		}
		c[e.end] = true;
		ans += e.cost;
		for (int j = 0; j < a[e.end].size(); j++) {
			q.push(Edge(e.end, a[e.end][j].first, a[e.end][j].second));
		}
	}

	cout << ans << endl;
	return 0;
}