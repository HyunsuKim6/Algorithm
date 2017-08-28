#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long init(vector<long long> &tree, vector<long long> &a, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(tree, a, 2 * node, start, (start + end) / 2) + init(tree, a, 2 * node + 1, (start + end) / 2 + 1, end);
	}
}

void lazy_update(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}


void range_update(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int i, int j, long long diff) {
	lazy_update(tree, lazy, node, start, end);
	if (start>j || end<i) {
		return;
	}
	if (i <= start && end <= j) {
		tree[node] += (end - start + 1)*diff;
		if (start != end) {
			lazy[2 * node] += diff;
			lazy[2 * node + 1] += diff;
		}
		return;
	}
	range_update(tree, lazy, 2 * node, start, (start + end) / 2, i, j, diff);
	range_update(tree, lazy, 2 * node + 1, (start + end) / 2 + 1, end, i, j, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long sum(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int i, int j) {
	lazy_update(tree, lazy, node, start, end);
	if (start>j || end<i) {
		return 0;
	}
	if (i <= start && end <= j) {
		return tree[node];
	}
	return sum(tree, lazy, node * 2, start, (start + end) / 2, i, j) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m += k;
	vector<long long> a(n);
	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1)) - 1;

	vector<long long> tree(tree_size);
	vector<long long> lazy(tree_size);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	init(tree, a, 1, 0, n - 1);

	while (m--) {
		int s;
		scanf("%d", &s);
		if (s == 1) {
			int start, end;
			long long diff;
			scanf("%d %d %lld", &start, &end, &diff);
			range_update(tree, lazy, 1, 0, n - 1, start - 1, end - 1, diff);
		}
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", sum(tree, lazy, 1, 0, n - 1, start - 1, end - 1));
		}
	}

	return 0;
}