#include <iostream>

using namespace std;

int n;
int d[110][110];

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == 1 && d[k][j] == 1) {
					d[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << ' ';
		}
		puts("");
	}

	return 0;
}