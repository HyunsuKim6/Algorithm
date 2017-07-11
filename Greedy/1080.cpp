#include <iostream>

using namespace std;

int a[51][51];
int b[51][51];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	int cnt = 0;

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-2; j++) {
			if (a[i][j] != b[i][j]) {
				cnt++;
				for (int x = i; x < i+3; x++) {
					for (int y = j; y < j+3; y++) {
						if (a[x][y] == 1) {
							a[x][y] = 0;
						}
						else{
							a[x][y] = 1;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << cnt << endl;
}