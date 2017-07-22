#include <iostream>
#include <string>
#include <set>
#include <functional>

using namespace std;

set<string,greater<string>> s;

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

	for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}