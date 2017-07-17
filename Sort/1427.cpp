#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	string a;
	cin >> a;
	sort(a.begin(), a.end(),cmp);
	cout << a <<endl;
}