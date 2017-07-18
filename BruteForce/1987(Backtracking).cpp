#include <iostream>
#include <map>

using namespace std;

int ans = 0;
char A[30][30];
map<char, int> check;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int row, col;

void go(int m,int x,int y) {
	if (ans < m) {
		ans = m;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row&&ny >= 0 && ny < col) {
			if (check[A[nx][ny]] == 0) {
				check[A[nx][ny]] = 1;
				go(m + 1, nx, ny);
				check[A[nx][ny]] = 0;
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> A[i][j];
		}
	}

	check[A[0][0]] = 1;
	go(1,0,0);

	cout << ans << endl;
	
	return 0;
}