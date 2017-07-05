#include <iostream>

using namespace std;

int main() {
	int n, count = 0 ,tmp;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		tmp = i;
		while (tmp % 5 == 0) {
			count++;
			tmp /= 5;
		}
	}

	cout << count << endl;
}