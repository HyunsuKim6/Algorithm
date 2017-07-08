#include <iostream>
#include <vector>

using namespace std;

int K, V, E;
vector<int> a[20003];
int check[20003] = { 0 };

void dfs(int node, int color) {
	check[node] = color;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == 0) {
			if (color == 1) {
				dfs(next, 2);
			}
			else {
				dfs(next, 1);
			}
		}
	}
}

int main() {
	int n, m;

	cin >> K;

	while (K--) {
		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			cin >> n >> m;
			a[n].push_back(m); a[m].push_back(n);
		}

		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;

		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				if (check[i] == check[a[i][j]]) {
					ok = false;
				}
			}
		}

		cout << (ok ? "Yes" : "NO") << endl;
	}
	return 0;
}