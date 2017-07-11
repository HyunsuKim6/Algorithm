#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a;

int main() {
	cin >> a;

	bool flag = false;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '0') {
			flag = true;
		}
	}

	if (!flag) {
		cout << -1 << endl;
		return 0;
	}

	int Answer = 0;

	for (int i = 0; i < a.length(); i++) {
		Answer += a[i] - '0';
	}

	if (Answer % 3 == 0) {
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		cout << a << endl;
	}
	else {
		cout << -1 << endl;
	}
}