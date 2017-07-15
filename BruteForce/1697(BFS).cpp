#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int check[100010] = { 0 };

void bfs(int start, int end) {
	int ans = 1;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			int k = q.front(); q.pop(); check[k] = 1;
			if (2 * k == end || k + 1 == end || k - 1 == end) {
				cout << ans << endl;
				return;
			}
			else {
				if (2 * k <= 100000) { if (check[2 * k] == 0) q.push(2 * k); }
				if (k + 1 <= 100000) { if (check[k + 1] == 0) q.push(k + 1); }
				if (k - 1 >= 0) { if (check[k - 1] == 0) q.push(k - 1); }
			}
		}
		ans++;
	}
}

int main() {
	int N, K;

	cin >> N >> K;

	if (N == K) {
		cout << 0 << endl;
		return 0;
	}

	bfs(N, K);

	return 0;
}