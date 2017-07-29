#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000007;

vector<vector<long long>> calc(vector<vector<long long>>& a, vector<vector<long long>>& b){
	vector<vector<long long>> ans(2,vector<long long>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}

	return ans;
}

int main() {
	long long n;

	cin >> n;
	n--;

	vector<vector<long long>> ans = { {1,0},{0,1} };
	vector<vector<long long>> a = { {1,1},{1,0} };

	while (n > 0) {
		if (n % 2 == 1) {
			ans = calc(ans, a);
		}
		a = calc(a, a);
		n /= 2;
	}

	cout << ans[0][0] % mod << endl;

	return 0;
}