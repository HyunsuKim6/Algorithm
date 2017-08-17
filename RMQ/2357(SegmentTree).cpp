#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];
int st[500000];
int bt[500000];

void sinit(int node, int start, int end) {
	if (start == end) {
		st[node] = a[start];
		return;
	}
	sinit(2 * node, start, (start + end) / 2);
	sinit(2 * node + 1, (start + end) / 2 + 1, end);
	st[node] = min(st[2 * node], st[2 * node + 1]);
}

void binit(int node, int start, int end) {
	if (start == end) {
		bt[node] = a[start];
		return;
	}
	binit(2 * node, start, (start + end) / 2);
	binit(2 * node + 1, (start + end) / 2 + 1, end);
	bt[node] = max(bt[2 * node], bt[2 * node + 1]);
}

int squery(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return -1;
	if (i <= start && end <= j) return st[node];
	int m1 = squery(2 * node, start, (start + end) / 2, i, j);
	int m2 = squery(2 * node + 1, (start + end) / 2 + 1, end , i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}

int bquery(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return -1;
	if (i <= start && end <= j) return bt[node];
	int m1 = bquery(2 * node, start, (start + end) / 2, i, j);
	int m2 = bquery(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return max(m1, m2);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sinit(1, 0, n - 1);
	binit(1, 0, n - 1);

	while (m--) {
		int start, end;
		scanf("%d %d", &start, &end);
		start--;
		end--;
		printf("%d %d\n", squery(1, 0, n - 1, start, end), bquery(1, 0, n - 1, start, end));
	}

	return 0;
}