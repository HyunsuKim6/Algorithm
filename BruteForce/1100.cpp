#include <iostream>
#include <string>

using namespace std;

string a[8];

int main() {
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (a[i][j] == 'F') {
					ans += 1;
				}
			}
		}
	}
	cout << ans << endl;
}