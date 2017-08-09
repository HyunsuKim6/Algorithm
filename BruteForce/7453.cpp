#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[5000];
int B[5000];
int C[5000];
int D[5000];

vector<int> fir, sec;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fir.push_back(A[i] + B[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sec.push_back(-(C[i] + D[j]));
		}
	}

	long long ans = 0;

	sort(sec.begin(), sec.end());

	for (int i = 0; i < fir.size(); i++) {
		auto temp = equal_range(sec.begin(), sec.end(), fir[i]);
		ans += temp.second - temp.first;
	}

	cout << ans << endl;

	return 0;
}