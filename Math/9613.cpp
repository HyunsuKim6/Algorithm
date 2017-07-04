#include <iostream>

using namespace std;


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int main() {
	//freopen("Text.txt", "r", stdin);

	int T , n;
	int g, Answer = 0;
	int a[110];

	cin >> T;
	while (T--) {

		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				Answer += gcd(a[i], a[j]);
			}
		}

		cout << Answer << endl;
		Answer = 0;

	}
}