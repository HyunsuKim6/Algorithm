#include <iostream>
#include <algorithm>

using namespace std;

int A[1010];
int D1[1010];
int D2[1010];

int main() {
	freopen("Text.txt", "r", stdin);

	int N;
	int Answer = 0 , tmp = 0;
	int mx1 = 0 , mx2 = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		D1[i] = 1;
		D2[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				D1[i] = max(D1[i], D1[j] + 1);
			}
		}
	}

	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j >= i; j--) {
			if (A[j] < A[i]) {
				D2[i] = max(D2[i], D2[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		Answer = max(Answer, D1[i]+D2[i]-1);
	}

	cout << Answer << endl;
}