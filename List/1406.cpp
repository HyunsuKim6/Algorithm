#include <iostream>
#include <list>

using namespace std;

int main() {
	char c;
	list<char> l;

	while (1) {
		scanf("%c", &c);
		if (c == '\n') {
			break;
		}
		l.push_back(c);
	}

	int T;
	cin >> T;

	auto it = l.end();

	while (T--) {
		cin >> c;
		if (c == 'P') {
			char x;
			cin >> x;
			l.insert(it, x);
		}
		else if (c == 'L') {
			if (it != l.begin()) {
				it--;
			}
		}
		else if (c == 'D') {
			if (it != l.end()) {
				it++;
			}
		}
		else if (c == 'B') {
			if (it != l.begin()) {
				it--;
				l.erase(it);
			}
		}
	}

	for (char c : l) {
		cout << c;
	}
	puts("");
	return 0;
}