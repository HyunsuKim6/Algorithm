#include <iostream>

using namespace std;

int dp[1000] = { 0 };

int go(int input) {
	if (input == 1) {
		return 1;
	}
	if (input == 2) {
		return 2;
	}
	if (input == 3) {
		return 4;
	}
	if (dp[input] != 0) {
		return dp[input];
	}

	return dp[input] = (go(input - 1) + go(input - 2) + go(input - 3));

}

int main() {
	//freopen("Text.txt", "r", stdin);
	
	int T,input;

	cin >> T;
	
	while (T--) {
		cin >> input;
		cout << go(input) << endl;
	}

	return 0;
}

