#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];
int t[500000];

void init(int node, int start, int end) {
	if (start == end) {
		t[node] = a[start];
	}
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		t[node] = min(t[node * 2], t[node * 2 + 1]);
	}
}

int query(int node, int start, int end, int i, int j) {
	if (i > end || j < start) {
		return -1;
	}
	if (i <= start&&end <= j) {
		return t[node];
	}
	int m1 = query(2 * node, start, (start + end) / 2, i, j);
	int m2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);

}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	init(1, 0, n - 1);

	while (m--) {
		int start, end;
		scanf("%d %d", &start, &end);
		start--;
		end--;
		printf("%d\n", query(1, 0, n - 1, start, end));
	}

	return 0;
}