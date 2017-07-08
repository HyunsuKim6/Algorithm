#include <iostream>
#include <algorithm>

using namespace std;

pair <int, int> a[500010];

int main() {
	
	int n,Answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		if (Answer < a[i].second - i) {
			Answer = a[i].second - i;
		}
	}

	cout << Answer << endl;

	return 0;
}