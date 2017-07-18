#include <iostream>

using namespace std;

int go(int count, int sum, int goal) {
	if (sum > goal) {
		return 0;
	}
	if (sum == goal) {
		return 1;
	}
	int cnt = 0;
	for (int i = 1; i <= 3; i++) {
		cnt+=go(count+1,sum + i, goal);
	}
	return cnt;
}

int main() {
	int T;

	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		cout << go(0,0, n) << endl;
	}
	return 0;
}