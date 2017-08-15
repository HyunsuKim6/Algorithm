#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100010;
vector<int> a[MAX];
int p[MAX][18];
int tin[MAX];
int tout[MAX];
int timer = 0;
int l;

void dfs(int v, int parent) {
	tin[v] = ++timer;
	p[v][0] = parent;
	for (int i = 1; i <= l; i++) {
		if (p[v][i - 1] != 0) {
			p[v][i] = p[p[v][i - 1]][i - 1];
		}
	}
	for (int i = 0; i < a[v].size(); i++) {
		int y = a[v][i];
		if(y!=parent) {
			dfs(y, v);
		}
	}
	tout[v] = ++timer;
}

bool upper(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int x, int y) {
	if (upper(x, y)) return x;
	if (upper(y, x)) return y;
	for (int i = l; i >= 0; i--) {
		if (!upper(p[x][i], y)) {
			x = p[x][i];
		}
	}
	return p[x][0];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (l = 1; (1 << l) <= n; l++);
	l -= 1;

	dfs(1, 1);

	int m;
	scanf("%d", &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", lca(x, y));
	}

	return 0;
}