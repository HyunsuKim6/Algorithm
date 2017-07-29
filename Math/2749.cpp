#include <iostream>
#include <cstring>

using namespace std;

long long d[1500010];
long long m = 1000000;

long long fib(int num) {
	if (d[num]!=-1) return d[num];

	return d[num] = (fib(num - 1)%m + fib(num - 2)%m)%m;
}

int main() {
	long long n;
	cin >> n;
	n %= 1500000;

	memset(d, -1, sizeof(d));

	d[0] = 0; d[1] = 1;

	fib(n);

	cout << d[n] % m << endl;
}