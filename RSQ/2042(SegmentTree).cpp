#include <iostream>

using namespace std;

long long a[1000010];
long long tree[5000010];

void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int i, int diff, int start, int end) {
	if (i < start || i > end) {
		return;
	}

	tree[node] += diff;

	if (start != end) {
		update(node * 2, i, diff, start, (start + end) / 2);
		update(node * 2 + 1, i, diff, (start + end) / 2 + 1, end);
	}
}

long long sum(int node, int start, int end, int i, int j) {
	if (end<i || start>j) {
		return 0;
	}
	if (i<=start&&end<=j) {
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, i, j) + sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	m += k;

	init(1, 0, n - 1);

	while (m--) {
		int c;
		scanf("%d", &c);
		if (c == 1) {
			long long index, value;
			scanf("%lld %lld", &index, &value);
			index--;
			int diff = value - a[index];
			a[index] = value;
			update(1, index, diff, 0, n - 1);
		}
		else {
			int s, e;
			scanf("%d %d", &s, &e);
			s--;
			e--;
			printf("%lld\n", sum(1, 0, n - 1, s, e));
		}
	}

	return 0;
}