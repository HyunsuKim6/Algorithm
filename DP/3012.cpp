#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const long long mod = 100000;
long long d[200][200];
bool over = false;

char open[5] = "({[";
char close[5] = ")}]";
string a;

long long go(int i, int j) {
	if (i > j) return 1;

	long long& ans = d[i][j];

	if (ans != -1) return ans;

	ans = 0;

	for (int k = i+1; k <= j; k += 2) {
		for (int l = 0; l < 3; l++) {
			if (open[l] == a[i] || a[i] == '?') {
				if (close[l] == a[k] || a[k] == '?') {
					ans += go(i + 1, k - 1) * go(k + 1, j);
					if (ans > mod) {
						over = true;
					}
					ans %= mod;
				}
			}
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	cin >> a;

	memset(d, -1, sizeof(d));

	long long ans = go(0, n - 1);

	if (over) {
		printf("%05lld\n", ans);
	}
	else {
		printf("%lld\n", ans);
	}
	return 0;
}