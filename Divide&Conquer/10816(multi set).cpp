#include <iostream>
#include <set>

using namespace std;

multiset<int> a;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.insert(x);
	}

	int m; cin >> m;

	while (m--) {
		int y;
		scanf("%d", &y);
		printf("%d ", a.count(y));
	}
	puts("");
	return 0;
}