#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s;
	
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		s.insert(x);
	}
	
	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		cout << s.count(x) << ' ';
	}
	return 0;
}