#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[510];
queue<int> q;
int work[510];
int ind[510];
int d[510];
int n;

void bfs() {
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			d[i] = work[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < a[now].size(); i++) {
			int next = a[now][i];
			ind[next]--;
			if (d[next] < d[now] + work[next]) {
				d[next] = d[now] + work[next];
			}
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
	return;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> work[i];
		int x;
		cin >> x;
		while (x != -1) {
			a[x].push_back(i);
			ind[i]++;
			cin >> x;
		}
	}

	bfs();

	for (int i = 1; i <= n; i++) {
		cout << d[i] << endl;
	}

	return 0;
}