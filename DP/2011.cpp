#include <iostream>
#include <string>

#define mod 1000000

using namespace std;

long long d[5010] = { 0 };

int main() {
	//freopen("Text.txt", "r", stdin);

	string a;

	cin >> a;

	int n = a.length();
	int tmp;

	if (a[0] == '0') {
		cout << 0 << endl;
		return 0;
	}

	d[0] = 1;

	tmp = a[1] - '0';

	if (tmp > 0) d[1] = (d[1] + d[0]) % mod;

	tmp = (a[0] - '0') * 10 + a[1] - '0';

	if (tmp >= 10 && tmp <= 26) d[1] = (d[1] + 1) % mod;

	for (int i = 2; i < n; i++) {
		tmp = a[i] - '0';

		if (tmp > 0) d[i] = (d[i] + d[i - 1]) % mod;

		tmp = (a[i - 1] - '0') * 10 + a[i] - '0';

		if(tmp>=10 && tmp<=26) d[i] = (d[i] + d[i - 2]) % mod;
	}
	

	cout << d[n - 1] << endl;
}