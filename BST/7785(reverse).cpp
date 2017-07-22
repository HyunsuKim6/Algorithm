#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		if (b == "enter") {
			s.insert(a);
		}
		else {
			s.erase(a);
		}
	}

	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << endl;
	}

	return 0;
}