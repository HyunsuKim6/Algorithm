#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> d;

int main() {
	freopen("Text.txt", "r", stdin);
	int T;
	cin >> T;

	while (T--) {
		int x;
		string a;
		cin >> a;
		if (a == "push_back") {
			cin >> x;
			d.push_back(x);
			continue;
		}
		else if (a == "push_front") {
			cin >> x;
			d.push_front(x);
			continue;
		}
		else if (a == "size") {
			cout << d.size() << '\n';
			continue;
		}
		else if (a == "empty") {
			cout << d.empty() << '\n';
			continue;
		}
		
		if (!d.empty()) {
			if (a == "front") {
				cout << d.front() << '\n';
			}
			else if (a == "back") {
				cout << d.back() << '\n';
			}
			else if (a == "pop_front") {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else if (a == "pop_back") {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else {
			cout << -1 << '\n';
		}
	}
	return 0;
}