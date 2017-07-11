#include <iostream>
#include <string>

using namespace std;

string a,b;

int main() {
	freopen("Text.txt", "r", stdin);

	int sign = 1, num;

	cin >> a;

	int Answer = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '+'){
			num = stoi(b);
			Answer += sign * num;
			b.clear();
		}
		else if (a[i] == '-') {
			num = stoi(b);
			Answer += sign * num;
			sign = -1;
			b.clear();
		}
		else {
			b += a[i];
		}
	}
	num = stoi(b);
	Answer += sign * num;

	cout << Answer << endl;
}