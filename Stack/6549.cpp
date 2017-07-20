#include <iostream>
#include <stack>

using namespace std;

long long a[100010];

int main() {
	while (1) {
		stack<long long> s;
		long long ans = 0;
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			while (!s.empty() && a[s.top()] > a[i]) {
				long long height = a[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) {
					width = i - s.top() - 1;
				}
				if (ans < height * width) {
					ans = height * width;
				}
			}
			s.push(i);
		}

		while (!s.empty()) {
			long long height = a[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < height * width) {
				ans = height * width;
			}
		}

		cout << ans << endl;
	}
	return 0;
}