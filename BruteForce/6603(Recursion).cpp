#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[20];
int ans[7];
int check[60];

void go(int n, int size,int index) {
	if (size == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		return;
	}

	if (n == index) return;

	ans[size] = arr[index];
	go(n, size + 1, index + 1);
	ans[size] = 0;
	go(n, size, index + 1);
}

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		
		memset(check, 0, sizeof(check));
		memset(ans, 0, sizeof(ans));
		
		go(n,0,0);

		cout << endl;
	}
	return 0;
}