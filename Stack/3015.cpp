#include <iostream>
#include <stack>

using namespace std;

int a[500010];

int main() {
	long long n, ans = 0;
	stack<pair<int, int>> s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		pair<int, int> p = { a[i],1 };
		while (!s.empty()) {
			if (a[i] >= s.top().first) {
				ans += (long long) s.top().second;
				if (a[i] == s.top().first) {
					p.second += s.top().second;
				}
				s.pop();
			}
			else {
				ans++;
				break;
			}
		}
		s.push(p);
	}

	cout << ans << endl;
	return 0;
}