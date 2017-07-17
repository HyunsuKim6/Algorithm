#include <iostream>
#include <queue>

using namespace std;

int check[210][210];
int ans[210];

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int sum = c;

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	check[0][0] = 1;
	ans[c] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		q.pop();

		//x->y
		int nx = 0; 
		int ny = y + x;
		int nz = z;
	
		if (ny >= b) {
			nx = ny - b;
			ny = b;
		}
		if (check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if(nx==0){
				ans[nz] = 1;
			}
		}

		//x->z
		nx = 0;  ny = y; nz = z + x;

		if (nz >= c) {
			nx = nz - c;
			nz = c;
		}
		if (check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				ans[nz] = 1;
			}
		}

		//y->x
		nx = x + y; ny = 0; nz = z;

		if (nx >= a) {
			ny = nx - a;
			nx = a;
		}
		if (check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				ans[nz] = 1;
			}
		}
	
		//y->z
		nx = x; ny = 0; nz = y + z;

		if (nz >= c) {
			ny = nz - c;
			nz = c;
		}
		if (check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				ans[nz] = 1;
			}
		}

		//z->x
		nx = x + z; ny = y; nz = 0;

		if (nx >= a) {
			nz = nx - a;
			nx = a;
		}
		if (check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				ans[nz] = 1;
			}
		}

		//z->y
		nx = x; ny = y + z; nz = 0;

		if (ny >= b) {
			nz = ny - b;
			ny = b;
		}
		if (check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				ans[nz] = 1;
			}
		}
	}

	for (int i = 0; i < 201; i++) {
		if (ans[i]) {
			cout << i << ' ';
		}
	}
	puts("");
	return 0;
}