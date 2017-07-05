#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(const pair<string, pair<int, pair<int, int>>> &u, const pair<string, pair<int, pair<int, int>>> &v) {
	if (u.second.first == v.second.first) {
		if (u.second.second.first == v.second.second.first) {
			if (u.second.second.second == v.second.second.second) {
				return u.first < v.first;
			}
			return -u.second.second.second < -v.second.second.second;
		}
		return u.second.second.first < v.second.second.first;
	}
	return -u.second.first < -v.second.first;
}

/*bool cmp(const pair<string, pair<int, pair<int, int>>> &u, const pair<string, pair<int, pair<int, int>>> &v) {
	return make_tuple(-u.second.first, u.second.second.first, -u.second.second.second, u.first) <
		make_tuple(-v.second.first, v.second.second.first, -v.second.second.second, v.first);
}*/

int main() {
	int n;

	cin >> n;

	vector<pair<string,pair<int,pair<int,int>>>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second.first>>a[i].second.second.first>>a[i].second.second.second;

	}

	sort(a.begin(), a.end(),cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].first << '\n';
	}
}