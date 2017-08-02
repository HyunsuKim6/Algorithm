#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int start, end, cost;

	Edge() : start(0),end(0),cost(0) {
	}
	Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {
	}
	bool operator < (Edge& other) {
		return cost < other.cost;
	}
};

int p[10010];

int find(int x) {
	if (x == p[x]) {
		return x;
	}
	else {
		return p[x] = find(p[x]);
	}
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
}

vector<Edge> a;

int main() {
	int v, e;

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		p[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back(Edge(x, y, z));
	}

	sort(a.begin(), a.end());

	int ans = 0;

	for (int i = 0; i < e; i++) {
		Edge e = a[i];
		int x = find(e.start);
		int y = find(e.end);
		if (x != y) {
			Union(x, y);
			ans += e.cost;
		}
	}

	cout << ans << endl;

	return 0;
}