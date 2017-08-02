#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int to, int cost) :to(to), cost(cost) {
	}
};

vector<Edge> a[1010];
int d[1010];
int inf = 100000000;
bool check[1010];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(Edge(y, z));
	}

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	int start, end;
	cin >> start >> end;

	d[start] = 0;

	for (int i = 0; i < n; i++) {
		int x, dist = inf + 1;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && dist > d[j]) {
				x = j;
				dist = d[j];
			}
		}
		check[x] = true;
		for (int j = 0; j < a[x].size(); j++) {
			if (d[a[x][j].to] > dist + a[x][j].cost) {
				d[a[x][j].to] = dist + a[x][j].cost;
			}
		}
	}

	cout << d[end] << endl;

	return 0;
}