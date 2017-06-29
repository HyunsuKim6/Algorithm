#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);
	
	int N;
	int P[1000];
	int dp[1000] = { 0 };

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}

