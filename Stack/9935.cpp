#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<pair<int, int>> s;
bool erased[1000010];

int main() {
	string a,cmp;

	cin >> a >> cmp;

	int m = cmp.length();

	if (m == 1) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == cmp[0]) {
				erased[i] = true;
			}
		}
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == cmp[0]) {
				s.push(make_pair(i, 0));
			}
			else {
				if (!s.empty()) {
					if (a[i] == cmp[s.top().second + 1]) {
						s.push(make_pair(i, s.top().second + 1));

						if (s.top().second == m - 1) {
							for (int j = 0; j < cmp.length(); j++) {
								erased[s.top().first] = true;
								s.pop();
							}
						}
					}
					else {
						while (!s.empty()) {
							s.pop();
						}
					}
				}
			}
		}
	}

	bool printed = false;
	for (int i = 0; i < a.length(); i++) {
		if (erased[i] == true) continue;
		cout << a[i] ;
		printed = true;
	}
	if (!printed) {
		cout << "FRULA" << endl;
	}
	puts("");
	return 0;
}