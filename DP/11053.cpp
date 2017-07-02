#include <iostream>
#include <algorithm>

using namespace std;

int A[1010];
int D[1010];

int main() {
	freopen("Text.txt", "r", stdin);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		D[i]=1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				D[i] = max(D[j] + 1, D[i]);
			}
		}
	}

	int Answer=0;

	for (int i = 0; i < N; i++) {
		Answer = max(Answer, D[i]);
	}

	cout << Answer << endl;
}