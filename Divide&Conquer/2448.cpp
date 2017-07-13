#include <iostream>

using namespace std;

int a[8000][4000] = { 0 };

void star(int x,int y, int h) {
	if (h == 3) {
		a[x][y] = 1;
		a[x - 1][y + 1] = 1;
		a[x + 1][y + 1] = 1;
		a[x - 2][y + 2] = 1;
		a[x - 1][y + 2] = 1;
		a[x][y + 2] = 1;
		a[x + 1][y + 2] = 1;
		a[x + 2][y + 2] = 1;
		return;
	}

	star(x, y, h/ 2);
	star(x - h / 2, y + h / 2, h / 2);
	star(x + h / 2, y + h / 2, h / 2);
}

int main() {

	int n;

	cin >> n;

	star(4000, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 4000 - n +1; j < 4000+n; j++) {
			if (a[j][i] == 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}

}