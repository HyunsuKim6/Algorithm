#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[100010];
int check[100010];
int parent[100010];
queue<int> q;

void bfs(int x) {
	check[x] = 1;
	parent[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < a[y].size(); i++) {
			int z = a[y][i];
			if (check[z] == 0) {
				parent[z] = y;
				check[z] = 1;
				q.push(z);
			}
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d %d",&v,&u);
		a[v].push_back(u); a[u].push_back(v);
	}

	bfs(1);

	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
}