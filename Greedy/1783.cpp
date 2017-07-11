#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	if (N == 1) {
		cout << 1 << endl;
	}
	else if (N == 2) {
		cout << min(4, (M + 1) / 2) << endl;
	}
	else {
		if (M > 7) {
			cout << M - 2 << endl;
		}
		else {
			cout << min(4, M) << endl;
		}
	}
}