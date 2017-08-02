#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[1010][3];
int d[1010][3];
int n;

int go(int index, int color) {
	if (index == n) return 0;

	int& ans = d[index][color];

	if (ans != -1) return ans;

	for (int k = 0; k < 3; k++) {
		if (k != color) {
			int temp = go(index + 1,k) + a[index][color];
			if (ans == -1 || ans > temp) {
				ans = temp;
			}
		}
	}

	return ans;
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	memset(d,-1,sizeof(d));

	int ans = min({ go(0, 0), go(0, 1), go(0, 2) });

	cout << ans << endl;

	return 0;
}