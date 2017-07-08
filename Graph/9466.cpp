#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100010];
int r[100010];
int s[100010];

int dfs(int x, int cnt,int state) {
	if (r[x] != 0) {
		if (s[x] != state) {
			return 0;
		}
		return cnt - r[x];
	}

	r[x] = cnt;
	s[x] = state;
	
	return dfs(a[x], cnt + 1, state);
}

int main() {
	freopen("Text.txt", "r", stdin);

	int T,n, Answer = 0;

	cin >> T;

	while (T--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			r[i] = 0;
			s[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			Answer += dfs(i, 1, i);
		}

		cout << n-Answer << endl;

		Answer = 0;
	}
}