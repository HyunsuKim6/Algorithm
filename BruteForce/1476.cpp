#include <iostream>

using namespace std;

int main() {
	int E=1, S=1, M=1;

	int count = 1;

	int Ea, Sa, Ma;

	cin >> Ea >> Sa >> Ma;

	while (1) {
		if (E == Ea&&S == Sa&&M == Ma) {
			cout << count << endl;
			return 0;
		}
		E %= 15; E++;
		S %= 28; S++;
		M %= 19; M++;
		count++;
	}
}