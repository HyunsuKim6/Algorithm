#include <iostream>

using namespace std;

int p[1000010] = { 0 };

int main() {
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a;

	for (int i = 2; i <= 1000000; i++) {
		if (!p[i]) {
			for (int j = i * 2; j <= 1000000; j += i) {
				p[j] = true;
			}
		}
	}

	cin >> a;

	while (a != 0) {

		for (int i = a-2; i >= 1; i--) {
			if (!p[i]&&!p[a-i]) {
				cout << a << " = " << a - i << " + " << i << '\n';
				break;
			}
		}

		cin >> a;
	}
}