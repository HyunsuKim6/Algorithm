#include <iostream>

using namespace std;

int arr[30];

int main() {
	int N, S, sum = 0, ans = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < (1 << N); i++) {
		for (int k = 0; k < N; k++) {
			if (i&(1 << k)) {
				sum += arr[k];
			}
		}
		if (sum == S) {
			ans++;
		}
		sum = 0;
	}

	cout << ans << endl;
}