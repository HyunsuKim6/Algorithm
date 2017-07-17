#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int c[10010] = { 0 };
int dist[10010] = { 0 };
bool prime[10010] = { 0 };

int change(int num, int index, int cn) {
	if (index == 0 && cn == 0) return -1;
	string a;
	a=to_string(num);
	a[index] = cn + '0';
	return stoi(a);
}

int main() {
	for (int i = 2; i <= 10000; i++) {
		for (int j = i*2; j <= 10000; j+=i) {
			if (prime[j] == 0) {
				prime[j] = true;
			}
		}
	}
	
	int T;
	cin >> T;

	while (T--) {
		int start, end;
		cin >> start >> end;

		memset(c, 0, sizeof(c));
		memset(dist, 0, sizeof(dist));

		queue<int> q;
		q.push(start);
		c[start] = 1;

		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if (next == -1) {
						continue;
					}
					if (c[next] == 0&&prime[next]==0) {
						c[next] = 1;
						dist[next] = dist[now] + 1;
						q.push(next);
					}
				}
			}
		}	
		cout << dist[end] << endl;
	}
}