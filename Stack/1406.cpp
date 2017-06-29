#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	freopen("Text.txt", "r", stdin);
	stack<char> s1,s2;
	string a;
	char b,c;

	cin >> a;

	for (int i = 0; i < a.length(); i++) {
		s1.push(a[i]);
	}

	int T;

	cin >> T;

	while (T--) {
		cin >> b;

		if (b == 'L') {
			if (s1.empty()) {
				continue;
			}
			else {
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if (b == 'D') {
			if (s2.empty()) {
				continue;
			}
			else {
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if (b == 'B') {
			if (s1.empty()) {
				continue;
			}
			else {
				s1.pop();
			}
		}
		else if (b == 'P') {
			cin >> c;
			s1.push(c);
		}
	}

	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}

	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
	return 0;
}
