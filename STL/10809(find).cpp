#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	freopen("Text.txt", "r", stdin);
	string sen;
	string a;
	while (cin >> a) {
		sen += a;
	}

	istringstream sin(sen);
	string num;
	int ans = 0;

	while (getline(sin, num, ',')) {
		ans += stoi(num);
	}

	cout << ans << endl;
	return 0;
}