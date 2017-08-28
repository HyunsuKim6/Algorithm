#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void lazy_update(vector<int> & tree, vector<int> & lazy, int node, int start, int end) {
	if (lazy[node] == 1) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[2 * node] ^= 1;
			lazy[2 * node + 1] ^= 1;
		}
		lazy[node] = 0;
	}
}

void range_update(vector<int> & tree, vector<int> & lazy, int node, int start, int end, int i, int j) {
	lazy_update(tree, lazy, node, start, end);
	if (start > j || end < i) {
		return;
	}
	if (i <= start && end <= j) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[2 * node] ^= 1;
			lazy[2 * node + 1] ^= 1;
		}
		return;
	}
	range_update(tree, lazy, 2 * node, start, (start + end) / 2, i, j);
	range_update(tree, lazy, 2 * node + 1, (start + end) / 2 + 1, end , i, j);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(vector<int> & tree, vector<int> & lazy, int node, int start, int end, int i, int j) {
	lazy_update(tree, lazy, node, start, end);
	if (start > j || end < i) {
		return 0;
	}
	if (i <= start && end <= j) {
		return tree[node];
	}

	return sum(tree, lazy, 2 * node, start, (start + end) / 2, i, j) + sum(tree, lazy, 2 * node + 1, (start + end) / 2 + 1, end , i, j);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);

	while (k--) {
		int s;
		scanf("%d", &s);
		if (s == 0) {
			int start, end;
			scanf("%d %d", &start, &end);
			range_update(tree, lazy, 1, 0, n - 1, start - 1, end - 1);
		}
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%d\n", sum(tree, lazy, 1, 0, n - 1, start - 1, end - 1));
		}
	}

	return 0;
}