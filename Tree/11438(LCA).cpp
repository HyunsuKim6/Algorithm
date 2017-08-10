#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100010;
vector<int> a[MAX];
int depth[MAX];
int parent[MAX];
int p[MAX][18];
bool check[MAX];

int lca(int x, int y) {
	if (depth[x] < depth[y]) {
		swap(x, y);
	}

	int log = 1;
	for (log = 1; (1 << log) <= depth[x]; log++);
	log -= 1;

	for (int i = log; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) {
			x = p[x][i];
		}
	}

	if (x == y) {
		return x;
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[x][i] != 0 && p[x][i] != p[y][i]) {
				x = p[x][i];
				y = p[y][i];
			}
		}
		return parent[x];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	depth[1] = 0;
	parent[1] = 0;
	check[1] = true;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				depth[y] = depth[x] + 1;
				parent[y] = x;
				check[y] = true;
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
	}

	for (int i = 1; (1 << i) <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (p[k][i - 1] != 0) {
				p[k][i] = p[p[k][i - 1]][i - 1];
			}
		}
	}

	int m;
	cin >> m;
	while (m--) {
		int x, y;
		scanf("%d %d",&x,&y);
		printf("%d\n",lca(x, y));;
	}

	return 0;
}