#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	long long a;
	string b;

	cin >> a;

	if (a == 0) {
		cout << 0 << endl;
		return 0;
	}

	while (a != 0) {
		int r = a % -2;
		if (r == -1) {
			r = 1;
			a /= -2;
			a += 1;
			b += (char)(r + '0');
			continue;
		}
		b += (char)(r+'0');
		a /= -2;
	}

	reverse(b.begin(), b.end());
	cout << b << endl;
}