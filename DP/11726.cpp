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
	if (dp[input] != 0) {
		return dp[input];
	}

	return dp[input] = ((go(input - 1)%10007) + (go(input - 2)%10007))%10007;

}

int main() {
	//freopen("Text.txt", "r", stdin);
	
	int input;

	cin >> input;

	cout << go(input) << endl;

	return 0;
}

