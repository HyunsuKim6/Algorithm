#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int to, int cost) :to(to), cost(cost) {}
};

vector<Edge> a[20010];
int d[20010];
bool check[20010];
int inf = 100000000;

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(Edge(y, z));
	}

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	priority_queue<pair<int, int>> q;
	d[start] = 0;
	q.push(make_pair(0,start));

	while(!q.empty()) {
		int x = q.top().second;
		int dist = -q.top().first;
		q.pop();
		if (check[x]) {
			continue;
		}
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j].to;
			if (d[y] > dist + a[x][j].cost) {
				d[y] = dist + a[x][j].cost;
				q.push(make_pair(-d[y],y));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == inf) {
			cout << "INF" << endl;
			continue;
		}
		cout << d[i] << endl;
	}

	return 0;
}