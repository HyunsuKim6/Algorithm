#include <iostream>

using namespace std;

int arr[30];
int N, S;
int ans = 0;

void go(int sum, int index) {
	if (index == N) {
		if (sum == S) {
			ans++;
		}
		return;
	}

	go(sum + arr[index], index + 1);
	go(sum, index + 1);
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	go(0, 0);

	if (S == 0) {
		ans--;
	}
	cout << ans << endl;
}