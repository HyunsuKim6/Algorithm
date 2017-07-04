#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	int n, b;
	string a;

	cin >> n >> b;

	while (n > 0) {
		int r = n%b;

		if (r < 10) {
			a += (char)(r + '0');
		}
		else {
			a += (char)(r - 10 + 'A');
		}

		n /= b;
	}

	reverse(a.begin(), a.end());
	cout << a << endl;
}