#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int from, to, cost;
	Edge():from(0),to(0),cost(0) {
	}
	Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {
	}
};

int d[501];
int inf = 100000000;

int main() {
	int n, m;
	cin >> n >> m;

	vector<Edge> a;

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back(Edge(x, y, z));
	}

	bool nc = false;

	d[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[a[j].to] > d[a[j].from] + a[j].cost) {
				d[a[j].to] = d[a[j].from] + a[j].cost;
				if (i == n) {
					nc = true;
				}
			}
		}
	}

	if (nc) {
		cout << -1 << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (d[i] == inf) cout << -1 << endl;
			else cout << d[i] << endl;
		}
	}

	return 0;
}