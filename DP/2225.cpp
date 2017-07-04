#include <iostream>

using namespace std;

long long d[210][210] = { 0 };

int main() {
	//freopen("Text.txt", "r", stdin);

	int N, K;

	cin >> N >> K;

	d[0][0] = 1;

	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			for(int k=0;k<=i;k++)
			d[i][j] += (d[k][j - 1] % 1000000000);
			d[i][j] %= 1000000000;
		}
	}

	cout << d[N][K] % 1000000000 << endl;
}