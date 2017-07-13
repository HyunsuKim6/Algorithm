#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<pair<int, long long>> a[100010];
int check[100010];

void bfs(int start, long long weight) {
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int z = q.front();
		q.pop();
		for (int i = 0; i < a[z].size(); i++) {
			int next = a[z][i].first;
			long long lim = a[z][i].second;
			if (check[next] == 0 && weight<=lim) {
				q.push(next);
				check[next] = 1;
			}
		}
	}
}

int main() {
	long long max = 0;
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		long long z;

		cin >> x >> y >> z;

		if (max < z) {
			max = z;
		}

		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}

	int start, end;
		
	cin >> start >> end;

	long long ans = 0;
	long long l = 0;
	long long r = max;

	while (l <= r) {
		long long mid = (l + r) / 2;

		memset(check, 0, sizeof(check));

		bfs(start, mid);

		if (check[end] == 1) {
			if (ans < mid) {
				ans = mid;
			}
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << endl;
}