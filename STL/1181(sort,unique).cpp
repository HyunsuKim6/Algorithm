#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string &a, string &b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	vector<string> a;
	string s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		a.push_back(s);
	}	

	sort(a.begin(), a.end(),cmp);

	auto it = unique(a.begin(), a.end());

	a.erase(it, a.end());

	for (auto i : a) {
		cout << i << '\n';
	}

	return 0;
}