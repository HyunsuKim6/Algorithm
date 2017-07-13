#include <iostream>

using namespace std;

int in[100001];
int post[100001];
int position[100001];

void solve(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) {
		return;
	}

	int root = post[pe];
	printf("%d ",root);
	int rp = position[root];
	int l = rp - is;

	solve(is, rp - 1, ps, ps + l - 1);
	solve(rp + 1, ie, ps + l, pe - 1);
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in[i];
		position[in[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}

	solve(0, n - 1, 0, n - 1);

	return 0;
}