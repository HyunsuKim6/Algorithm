#include <iostream>
#include <list>

using namespace std;

int main() {
	list<pair<int, int>> l;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		l.push_back(make_pair(x, i));
	}

	auto it = l.begin();

	for (int i = 0; i < n - 1; i++) {
		int move = it->first;
		
		cout << it->second << ' ';
		
		if (move > 0) {
			auto temp = it;
			temp++;
			if (temp == l.end()) {
				temp = l.begin();
			}
			l.erase(it);
			it = temp;
			for (int j = 1; j < move; j++) {
				it++;
				if (it == l.end()) {
					it = l.begin();
				}
			}
		}
		else {
			move = -move;
			auto temp = it;
			if (temp == l.begin()) {
				temp = l.end();
			}
			temp--;
			l.erase(it);
			it = temp;
			for (int j = 1; j < move; j++) {
				if (it == l.begin()) {
					it = l.end();
				}
				it--;		
			}
		}
	}

	cout << it->second << endl;

	return 0;
}