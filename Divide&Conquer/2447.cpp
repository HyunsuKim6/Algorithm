#include <iostream>
#include <string>

using namespace std;

string a[3000];

void star(int x, int y, int m, int blank) {
	if (blank == 1) {
		for (int i = y; i < y + m; i++) {
			for (int j = x; j < x + m; j++) {
				a[i] += ' ';
			}
		}
	}
	else {
		if (m == 1) {
			a[y] += '*';
			return;
		}

		int n = m / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) {
					star(x + n, y + n, n, 1);
					continue;
				}
				star(x + i*n, y + j*n, n, 0);
			}
		}

	}
}

int main() {
	int n;

	cin >> n;

	star(0, 0, n, 0);

	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}