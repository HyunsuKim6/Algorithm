#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int c[10010];
string a[10010];

int main() {
	int T;
	cin >> T;

	while (T--) {
		int start, end;
		cin >> start >> end;

		memset(c, 0, sizeof(c));
		for (int i = 0; i < 10010; i++) {
			a[i].clear();
		}

		queue<int> q;

		q.push(start);
		c[start] = 1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			
			int next = (now * 2) % 10000;
			if (c[next] == 0) {
				c[next] = 1;
				a[next] += a[now];
				a[next] += 'D';
				q.push(next);
			}
			
			next = ((now - 1) == -1) ? 9999 : now - 1;
			if (c[next] == 0) {
				c[next] = 1;
				a[next] += a[now];
				a[next] += 'S';
				q.push(next);
			}

			next = (now%1000)*10 + now/1000;
			if (c[next] == 0) {
				c[next] = 1;
				a[next] += a[now];
				a[next] += 'L';
				q.push(next);
			}

			next = (now % 10) * 1000 + now / 10;
			if (c[next] == 0) {
				c[next] = 1;
				a[next] += a[now];
				a[next] += 'R';
				q.push(next);
			}
		}
		cout << a[end] << endl;
	}
	return 0;
}