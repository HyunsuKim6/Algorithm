#include <iostream>
#include <map>

using namespace std;

char A[30][30];
map<char, int> check;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int row, col;

int go(int x,int y) {
	int ans = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row&&ny >= 0 && ny < col) {
			if (check[A[nx][ny]] == 0) {
				check[A[nx][ny]] = 1;
				int next = go(nx, ny);
				if (ans < next) {
					ans = next;
				}
				check[A[nx][ny]] = 0;
			}
		}
	}
	return ans + 1;
}

int main() {
	int ans = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> A[i][j];
		}
	}

	check[A[0][0]] = 1;
	ans = go(0,0);

	cout << ans << endl;
	
	return 0;
}