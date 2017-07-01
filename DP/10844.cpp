#include <iostream>

using namespace std;

int main() {
	long long d[110][10] = { 0 };
	int N;
	long long Answer = 0;

	cin >> N;

	for (int i = 1; i <= 9; i++) {
		d[0][i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				d[i][0] = d[i - 1][1];
			}
			else if (j == 9) {
				d[i][9] = d[i - 1][8];
			}
			else {
				d[i][j] = (d[i - 1][j + 1] + d[i - 1][j - 1]) % 1000000000;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		Answer += d[N - 1][i];
		Answer %= 1000000000;
	}

	cout << Answer << endl;
}