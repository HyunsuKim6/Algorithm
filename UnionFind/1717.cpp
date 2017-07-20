#include <iostream>

using namespace std;

int parent[1000010];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void uni(int x, int y) {
	int a = find(x);
	int b = find(y);
	parent[b]=a;
	return;
}

int main() {
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int sel,x,y;
		scanf("%d %d %d", &sel, &x, &y);
		if (sel == 0) {
			uni(x, y);
		}
		else {
			if (find(x) == find(y)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
}