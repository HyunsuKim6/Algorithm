#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);
	stack<int> s;
	string a;
	cin >> a;
	int n = a.size();
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == '(') {
			s.push(i);
		}
		else {
			if (i - s.top() == 1) {
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans += 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
