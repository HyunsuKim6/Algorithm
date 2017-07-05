#include <iostream>

using namespace std;

int p[1000010] = { 0 };

int main() {
	//freopen("Text.txt", "r", stdin);
	
	int a, b;

	cin >> a >> b;

	p[0] = 1;
	p[1] = 1;

	for (int i = 2; i <= b; i++) {
		if (!p[i]) {
			for (int j = i * 2; j <= b; j += i) {
				p[j] = true;
			}
		}
	}

	for (int i = a; i <= b; i++) {
		if (!p[i]) cout << i << endl;
	}
}