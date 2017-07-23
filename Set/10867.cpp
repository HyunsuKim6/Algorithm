#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s;
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		s.insert(x);
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
}