#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, string> &u, const pair<int, string> &v) {
	return u.first < v.first;
}

int main() {
	int n;

	cin >> n;

	vector<pair<int, string>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	stable_sort(a.begin(), a.end(),cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].first << ' ' << a[i].second << '\n';
	}
}