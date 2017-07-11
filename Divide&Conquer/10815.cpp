#include <iostream>
#include <algorithm>

using namespace std;

int a[500002];

int binsearch(int left,int right, int x) {
	while (left <= right) {
		int mid = (right + left) / 2;
		if (a[mid] == x) {
			return 1;
		}
		else if (a[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return 0;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int m; cin >> m;

	while (m--) {
		int x;
		scanf("%d", &x);
		printf("%d ",binsearch(0,n,x));
	}
	puts("");
	return 0;
}