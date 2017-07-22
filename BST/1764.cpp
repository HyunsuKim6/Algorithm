#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<string> s;

int main() {
	string a, b;
	vector<string> ans;
	int n, m;
	cin >> n >> m;

	while (n--) {
		cin >> a;
		s.insert(a);
	}
	while (m--) {
		cin >> b;
		if (s.count(b) > 0) {
			ans.push_back(b);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}