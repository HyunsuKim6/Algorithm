#include <iostream>

using namespace std;

int a[100010];

int main() {
	int n, s, ans = 500000;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left = 0, right = 0, sum = a[0];

	while (left <= right && right < n) {
		if (sum < s) {
			right++;
			sum += a[right];
		}
		else if (sum == s) {
			if (ans > (right - left + 1)) {
				ans = (right - left + 1);
			}
			right++;
			sum += a[right];
		}
		else if (sum > s) {
			if (ans > (right - left + 1)) {
				ans = (right - left + 1);
			}
			sum -= a[left];
			left++;
		}
	}
	
	if (ans == 500000) cout << 0 << endl;
	else cout << ans << endl;

	return 0;
}