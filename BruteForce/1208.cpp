#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[50];

vector<int> fir, sec;

int main() {
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m = n / 2;
	n = n - m;

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int k = 0; k < n; k++) {
			if (i&(1 << k)) {
				sum += a[k];
			}
		}
		fir.push_back(sum);
	}

	for (int i = 0; i < (1 << m); i++) {
		int sum = 0;
		for (int k = 0; k < m; k++) {
			if (i&(1 << k)) {
				sum += a[k+n];
			}
		}
		sec.push_back(sum);
	}

	sort(fir.begin(), fir.end());
	sort(sec.begin(), sec.end());
	reverse(sec.begin(), sec.end());

	int i = 0, j = 0, ans = 0;
	n = fir.size();
	m = sec.size();

	while (i < n&&j < m) {
		if (fir[i] + sec[j] == s) {
			int up = 1, down = 1;
			i++; j++;
			while (i < n&&(fir[i - 1] == fir[i])) {
				i++;
				up++;
			}
			while (j < m&&(sec[j - 1] == sec[j])) {
				j++;
				down++;
			}
			ans += up*down;
		}
		else if (fir[i] + sec[j] > s) {
			j++;
		}
		else {
			i++;
		}
	}

	if (s == 0) ans--;
	cout << ans << endl;

	return 0;
}