#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int to, int cost) :to(to), cost(cost) {}
};

vector<Edge> a[1001];
int d[1001];
int from[1001];
bool check[1001];
int inf = 100000000;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(Edge(y, z));
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}

	d[start] = 0;
	from[start] = -1;

	for (int i = 0; i < n - 1; i++) {
		int x = -1;
		int dist = inf + 1;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false && dist > d[j]) {
				x = j;
				dist = d[j];
			}
		}
		check[x] = true;
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j].to;
			if (d[y] > dist + a[x][j].cost) {
				d[y] = dist + a[x][j].cost;
				from[y] = x;
			}
		}
	}

	printf("%d\n", d[end]);

	stack<int> s;

	int x = end;

	while (x != -1) {
		s.push(x);
		x = from[x];
	}

	printf("%d\n", s.size());

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}