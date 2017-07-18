#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check(string ans) {
	int ja = 0;
	int mo = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
			mo += 1;
		}
		else {
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int len, vector<char> &a, string ans,int index) {
	if (len == ans.length()) {
		if (check(ans)) {
			cout << ans << endl;
		}
		return;
	}
	if (index >= a.size()) {
		return;
	}

	go(len, a, ans + a[index], index + 1);
	go(len, a, ans, index + 1);
}

int main() {
	int L, C;
	string ans;

	cin >> L >> C;

	vector<char> pos;

	for (int i = 0; i < C; i++) {
		char x;
		cin >> x;
		pos.push_back(x);
	}

	sort(pos.begin(), pos.end());

	go(L, pos, ans, 0);

	return 0;
}