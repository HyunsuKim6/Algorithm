#include <iostream>

using namespace std;

int a[10000010] = { 0 };

int main() {
	int n,tmp;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp]++;
	}

	for (int i = 0; i < 10000; i++) {
		if (a[i] > 0) {
			for (int j = 0; j < a[i]; j++) {
				cout << i << endl;
			}
		}
	}
}