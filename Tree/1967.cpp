#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> a[10002];
int check[10002];
int d[10002];

void bfs(int start) {
	queue<int> q;
	check[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].first;
			int z = a[x][i].second;
			if (check[y] == 0) {
				check[y] = 1;
				d[y] = d[x] + z;
				q.push(y);
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);

	int n;

	cin >> n;

	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}

	memset(check, 0, sizeof(check));
	memset(d, 0, sizeof(d));

	bfs(1);
	
	int start = 1;

	for (int i = 2; i <= n; i++) {
		if (d[start] < d[i]) {
			start = i;
		}
	}

	memset(check, 0, sizeof(check));
	memset(d, 0, sizeof(d));

	bfs(start);

	int Answer = 0;

	for (int i = 1; i <= n; i++) {
		if (Answer < d[i]) {
			Answer = d[i];
		}
	}

	cout << Answer << endl;

	return 0;

}