#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	string a;

	cin >> a;

	int b;

	int  Answer = 0;

	cin >> b;

	int n = a.length();

	for (int i = 0; i < n; i++) {
		double r;

		if (a[i] <= '9') {
			r = (int)(a[i] - '0');
		}
		else {
			r = (int)(a[i] - 'A' + 10);
		}

		r = r * pow(b, n-i-1);
		Answer += r;
	}

	cout << Answer << endl;
}