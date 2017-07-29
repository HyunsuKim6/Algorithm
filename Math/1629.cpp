#include <iostream>

using namespace std;

long long calc(int A, int B, int C) {
	if (B == 0) {
		return 1;
	}
	if (B == 1) {
		return A;
	}
	if (B % 2 == 1) {
		return (A*calc(A, B - 1, C))%C;
	}
	else {
		long long temp = calc(A, B / 2, C)%C;
		return (temp*temp) % C;
	}
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout<<calc(A, B, C)%C<<endl;
	return 0;
}