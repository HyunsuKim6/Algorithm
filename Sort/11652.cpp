#include <iostream>
#include <algorithm>

using namespace std;

long long a[1000010] = { 0 };

int main() {
	long long n, cnt = 0, num, max = 1;

	cin >> n;

for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	num = a[0];
	cnt = 1;

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}

		if (max < cnt) {
			max = cnt;
			num = a[i];
		}
	}

	cout << num << endl;

	return 0;
}