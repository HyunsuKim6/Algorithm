#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	int ans = 0;

	while (getline(cin, a, ',')) {
		int b = stoi(a);
		ans += b;
	}

	cout << ans << endl;
	return 0;
}