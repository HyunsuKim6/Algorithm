#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[11][11];

int main() {
	bool flag;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 100000000, res = 0;

	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		b[i] = i;
	}

	do {
		flag = true;
		res = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[b[i]][b[i + 1]] == 0) {
				flag = false;
				break;
			}
			res += a[b[i]][b[i + 1]];
		}
		if (flag) {
			if (a[b[n - 1]][b[0]] == 0) {
				continue;
			}
			res += a[b[n - 1]][b[0]];
			if (ans > res) {
				ans = res;
			}
		}

	} while (next_permutation(b.begin()+1, b.end()));

	cout << ans << endl;
}