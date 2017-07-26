#include <iostream>

using namespace std;

int a[50];
int d[50];

int main() {
	int n; 
	cin >> n;
	
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + 2 * a[i - 2];
	}

	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		int b;
		if (i % 2 == 1) {
			b = a[(i - 1) / 2];
		}
		else {
			b = a[i/2] +  2* a[(i - 2) / 2];
		}
		d[i] = (a[i] + b) / 2;
	}

	cout << d[n] << endl;
	return 0;
}