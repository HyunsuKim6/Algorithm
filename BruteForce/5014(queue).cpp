#include <iostream>
#include <queue>

using namespace std;

int check[1000010];
int dist[1000010];

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<int> q;

	q.push(S);
	check[S] = 1;
	dist[S] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();

		int next = now + U;
		if (next <= F) {
			if (check[next] == 0) {
				check[next] = 1;
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}

		next = now - D;
		if (next >= 0) {
			if (check[next] == 0) {
				check[next] = 1;
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}

	if (check[G]==0) {
		cout << "use the stairs\n" << endl;
	}
	else {
		cout << dist[G] << endl;
	}
}