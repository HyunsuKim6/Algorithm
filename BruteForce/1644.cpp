#include <iostream>
#include <vector>

using namespace std;

bool a[4000010];
vector<int> p;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i * 2; j <= n; j+=i) {
			a[j] = true;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (a[i] == false) {
			p.push_back(i);
		}
	}

	int left = 0, right = 0, ans = 0;
	int sum = p[0], m = p.size();
	p.push_back(0);

	while (left <= right && right < m) {
		if (sum < n) {
			right++;
			sum += p[right];
		}
		else if (sum == n) {
			ans++;
			right++;
			sum += p[right];
		}
		else if (sum > n) {
			sum -= p[left];
			left++;
		}
	}
	
	cout << ans << endl;

	return 0;
}