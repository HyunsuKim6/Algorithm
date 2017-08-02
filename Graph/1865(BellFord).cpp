#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[510];

struct Edge {
	int from, to, cost;
	Edge() :from(0), to(0), cost(0) {};
	Edge(int from, int to, int cost) :from(from), to(to), cost(cost) {};
};

int inf = 1000000000;

int main() {
	int T;
	cin >> T;
	while (T--) {
		fill(d, d + 510, inf);
		vector<Edge> a;
		int n, m, w;
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			a.push_back(Edge(x, y, z));
			a.push_back(Edge(y, x, z));
		}
		for (int i = 0; i < w; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			a.push_back(Edge(x, y, -z));
		}

		bool negative_cycle = false;

		d[1] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2*m+w; j++) {
				if (d[a[j].to] > d[a[j].from] + a[j].cost) {
					d[a[j].to] = d[a[j].from] + a[j].cost;
					if (i == n) {
						negative_cycle = true;
					}
				}
			}
		}

		if (negative_cycle) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}