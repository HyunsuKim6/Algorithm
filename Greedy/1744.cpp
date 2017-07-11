#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos;
vector<int> neg;
int zero = 0;

int main() {
	int n,one=0,zero=0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			one++;
		}
		else if (x == 0) {
			zero++;
		}
		else if (x > 0) {
			pos.push_back(x);
		}
		else {
			neg.push_back(x);
		}

	}

	sort(pos.begin(), pos.end());
	reverse(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int Answer = one;

	if (pos.size() % 2 == 1) {
		pos.push_back(1);
	}

	for (int j = 0; j < pos.size(); j += 2) {
		int x = pos[j];
		int y = pos[j + 1];
		int z = x*y;
		Answer += z;
	}

	if (neg.size() % 2 == 1) {
		if (zero > 0) {
			neg.push_back(0);
		}
		else {
			neg.push_back(1);
		}
	}

	for (int j = 0; j < neg.size(); j += 2) {
		int x = neg[j];
		int y = neg[j + 1];
		int z = x*y;
		Answer += z;
	}

	cout << Answer << endl;

	return 0;
}