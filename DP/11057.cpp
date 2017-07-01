#include <iostream>

using namespace std;

int main() {
	long long d[1010][10] = { 0 };
	int N;
	long long Answer = 0;

	cin >> N;

	for (int i = 0; i <= 9; i++) {
		d[0][i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		Answer += d[N-1][i];
		Answer %= 10007;
	}

	cout << Answer << endl;
}