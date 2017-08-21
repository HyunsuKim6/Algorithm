#include <iostream>

using namespace std;

long long tree[5000010];
int b = 1;

void update(int index, long long diff) {
	index += b;
	tree[index] += diff;
	while (index > 1) {
		tree[index / 2] += diff;
		index /= 2;
	}
}

long long sum(int l, int r) {
	long long ans = 0;
	l += b;
	r += b;
	while (l < r) {
		if (l % 2 == 0) {
			l /= 2;
		}
		else {
			ans += tree[l];
			l += 1;
			l /= 2;
		}
		if (r % 2 == 1) {
			r /= 2;
		}
		else {
			ans += tree[r];
			r -= 1;
			r /= 2;
		}
	}

	if (l == r) {
		ans += tree[l];
	}

	return ans;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m += k;

	while (b <= n) {
		b *= 2;
	}
	b -= 1;
	
	for (int i = 1; i <= n; i++) {
		long long value;
		scanf("%lld", &value);
		update(i, value);
	}

	while (m--) {
		int s;
		scanf("%d", &s);
		if (s == 1) {
			int index;
			long long value;
			scanf("%d %lld", &index, &value);
			update(index, value-tree[b+index]);
		}
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", sum(start, end));
		}
	}

	return 0;
}