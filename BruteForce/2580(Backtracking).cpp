#include <iostream>

using namespace std;

int sdk[10][10];
int coln[10][10];
int rown[10][10];
int box[10][10];

void go(int m) {
	if (m == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdk[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);
	}

	int x = m / 9;
	int y = m % 9;
	if (sdk[x][y] != 0) {
		go(m + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (rown[x][i] != 1 && coln[y][i] != 1 && box[(x / 3) * 3 + y / 3][i] != 1) {
				sdk[x][y] = i;
				rown[x][i] = 1;
				coln[y][i] = 1;
				box[(x / 3) * 3 + y / 3][i] = 1;
				go(m + 1);
				sdk[x][y] = 0;
				rown[x][i] = 0;
				coln[y][i] = 0;
				box[(x / 3) * 3 + y / 3][i] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdk[i][j];
			rown[i][sdk[i][j]] = 1;
			coln[j][sdk[i][j]] = 1;
			box[(i / 3) * 3 + j / 3][sdk[i][j]] = 1;
		}
	}

	go(0);

	return 0;
}