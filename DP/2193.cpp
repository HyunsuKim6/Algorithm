#include <iostream>

using namespace std;

int main() {
	long long d[100][2] = { 0 };
	int N;

	cin >> N;

	d[0][0] = 0;
	d[0][1] = 1;

	for (int i = 1; i < N; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	cout << d[N-1][0] + d[N-1][1] << endl;
}