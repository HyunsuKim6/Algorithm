#include <iostream>

using namespace std;

int parent[110];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {		
		return parent[x] = find(parent[x]);
	}
}

void uni(int x, int y) {
	int a = find(x);
	int b = find(y);
	parent[a] = b;
	return;
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int x, y;
		cin >> x >> y;

		uni(x, y);
	}
	
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (find(1)==find(i)) {
			ans++;
		}
	}

	cout << ans - 1 << endl;

	return 0;
}