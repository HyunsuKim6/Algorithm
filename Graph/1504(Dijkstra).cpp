#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int to, int cost) :to(to), cost(cost) {}
};

vector<Edge> a[1000];
int d[1000];
bool check[1000];
int n, m;
int inf = 100000000;

int go(int start,int end) {
	memset(d, 0, sizeof(d));
	memset(check, 0, sizeof(check));

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	d[start] = 0;

	for (int i = 0; i < n; i++) {
		int x = -1;
		int dist = inf + 1;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && dist > d[j]) {
				x = j;
				dist = d[j];
			}
		}
		check[x] = true;
		for (int j = 0; j <a[x].size(); j++) {
			if (d[a[x][j].to] > dist + a[x][j].cost) {
				d[a[x][j].to] = dist + a[x][j].cost;
			}
		}
	}

	return d[end];
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(Edge(y, z));
		a[y].push_back(Edge(x, z));
	}

	int mid1, mid2;
	cin >> mid1 >> mid2;

	int ans = min((go(1, mid1) + go(mid1, mid2) + go(mid2, n)), (go(1, mid2) + go(mid2, mid1) + go(mid1, n)));

	if (ans >= inf) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}