#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
map<int, int> dist;

int main() {
	freopen("Text.txt", "r", stdin);
	int num=0;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			x = 9;
		}
		num = num * 10 + x;
	}

	queue<int> q;
	q.push(num);
	dist[num] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		string now_s = to_string(now);
		int z = now_s.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next_s = now_s;
				swap(next_s[3 * x + y], next_s[3 * nx + ny]);
				int next = stoi(next_s);
				if (dist.count(next)==0) {
					dist[next] = dist[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << dist[123456789] << endl;
}