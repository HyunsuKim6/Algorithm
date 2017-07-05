#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long uct = 0, ucf=0, dct = 0, dcf = 0;

	long long a, b, tmp = 0;

	cin >> a >> b;

	for (long long i = 2; i <= a; i *= 2) {
		uct += a / i;
	}

	for (long long i = 5; i <= a; i *= 5) {
		ucf += a / i;
	}

	for (long long i = 2; i <= a-b; i *= 2) {
		tmp += (a-b) / i;
	}

	uct -= tmp;
	tmp = 0;

	for (long long i = 5; i <= a - b; i *= 5) {
		tmp += (a - b) / i;
	}

	ucf -= tmp;
	tmp = 0;


	for (long long i = 2; i <= b; i *= 2) {
		dct += b / i;
	}
	
	for (long long i = 5; i <= b; i *= 5) {
		dcf += b / i;
	}

	long long Answer = min(uct-dct,ucf-dcf);
	
	if (Answer < 1) {
		cout << 0 << endl;
	}
	else {
		cout << Answer << endl;
	}
}