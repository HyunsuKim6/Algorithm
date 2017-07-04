#include <iostream>
#include <string>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	string a,b;

	cin >> a;

	int n = a.length();

	if (n % 3 == 1) {
		b += "00";
		b += a;
	}
	else if (n % 3 == 2) {
		b += "0";
		b += a;
	}
	else {
		b += a;
	}

	n = b.length();

	for (int i = 0; i < n; i+=3){
		int r = (b[i]-'0') * 4 + (b[i + 1]-'0') * 2 + (b[i + 2]-'0') * 1;
		cout << r;
	}
}