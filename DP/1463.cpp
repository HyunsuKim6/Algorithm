#include <iostream>

using namespace std;

int dp[1000000] = { 0 };

int go(int input) {
	if (input == 1) return 0;
	if (dp[input] > 0) return dp[input];

	dp[input] = go(input - 1) + 1;

	if (input % 2 == 0) {
		int temp = go(input / 2) + 1;
		if (dp[input] > temp) dp[input] = temp;
	}
	if (input % 3 == 0) {
		int temp = go(input / 3) + 1;
		if (dp[input] > temp) dp[input] = temp;
	}

	return dp[input];
}

int main() {
	//freopen("Text.txt", "r", stdin);

	int input;

	cin >> input;

	cout << go(input) << endl;

	return 0;
}

