#include <iostream>

using namespace std;

int d[10];

int fib(int n) {
	if (d[n]>0) return d[n];
	return d[n] = n*fib(n - 1);
}

int main() {
	int n, k, ans;

	cin >> n >> k;

	d[1] = 1;

	ans = fib(n) / fib(k);
	ans /= fib(n - k);

	cout << ans << endl;
	
	return 0;
}