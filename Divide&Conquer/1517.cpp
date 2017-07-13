#include <iostream>

using namespace std;

int a[500010];
int b[500010];

long long solve(int start, int end) {
	if (start == end) {
		return 0;
	}

	int mid = (start + end) / 2;

	long long ans = solve(start, mid) + solve(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || a[i] <= a[j])) {
			b[k++] = a[i++];
		}
		else {
			ans += (long long)(mid - i + 1);
			b[k++] = a[j++];
		}
	}

	for (int l = start; l <= end; l++) {
		a[l++] = b[l - start];
	}

	return ans;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	cout << solve(0, n - 1) << endl;
}