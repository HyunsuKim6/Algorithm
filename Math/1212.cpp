#include <iostream>
#include <string>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	string a,b;

	cin >> a;

	switch (a[0]) {
	case '0':
		b += "0";
		break;
	case '1':
		b += "1";
		break;
	case '2':
		b += "10";
		break;
	case '3':
		b += "11";
		break;
	case '4':
		b += "100";
		break;
	case '5':
		b += "101";
		break;
	case '6':
		b += "110";
		break;
	case '7':
		b += "111";
		break;
	}


	for (int i = 1; i < a.length(); i++) {
		switch (a[i]) {
		case '0':
			b += "000";
			break;
		case '1':
			b += "001";
			break;
		case '2':
			b += "010";
			break;
		case '3':
			b += "011";
			break;
		case '4':
			b += "100";
			break;
		case '5':
			b += "101";
			break;
		case '6':
			b += "110";
			break;
		case '7':
			b += "111";
			break;
		}
	}

	cout << b << endl;
}