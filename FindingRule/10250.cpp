#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int H, W, N ,a,b,ans = 0;
		cin >> H >> W >> N;

		if (N % H == 0) {
			ans = N / H + H * 100;
			cout << ans << endl;
			continue;
		}

		a = N / H + 1;
		b = N%H;
		ans = 100 * b + a;
		cout << ans << endl;
	}

	return 0;
}