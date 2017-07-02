#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];
int d[100000];

int main() {
	freopen("Text.txt", "r", stdin);

	int n;
	int Answer = d[0];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	d[0] = a[0];

	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}
	
	for (int i = 1; i < n; i++) {
		Answer = max(Answer, d[i]);
	}

	cout << Answer << endl;
}