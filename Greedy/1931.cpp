#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> a;
pair<int, int> curr;

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second == y.second) {
		return  x.first < y.first;
	}
	return x.second < y.second;
}

int main() {
	//freopen("Text.txt", "r", stdin);

	int n,x,y;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		a.push_back(make_pair(x, y));
	}

	sort(a.begin(), a.end(), cmp);

	curr = a[0];

	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (curr.second <= a[i].first) {
			curr = a[i];
			cnt++;
		}
	}

	cout << cnt << endl;
}