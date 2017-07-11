#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
vector<long long> b;

int main() {
	int n, m;

	cin >> n >> m;

	n += m;

	while (n--) {
		long long x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++) {
		printf("%lld ", a[i]);
	}
}