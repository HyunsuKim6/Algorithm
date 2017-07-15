#include <iostream>
#include <math.h>

using namespace std;

int check[10] = { 0 };

int possible(int n) {
	int len = 0;
	if (n == 0) {
		if (check[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	while (n > 0) {
		if (check[n % 10] == 1) {
			return false;
		}
		n /= 10;
		len++;
	}
	return len;
}

int main() {
	int ch, n, answer = 1000000;

	cin >> ch >> n;

	while (n--) {
		int x;
		cin >> x;
		check[x] = 1;
	}

	for (int i = 0; i <= 1000000; i++) {
		int len;
		if (len = possible(i)) {
			if (abs(i - ch) + len < answer) {
				answer = abs(i - ch) + len;
			}
		}
	}

	if (abs(100 - ch) < answer) {
		answer = abs(100 - ch);
		cout << answer << endl;
		return 0;
	}
	
	cout << answer << endl;
	return 0;
}