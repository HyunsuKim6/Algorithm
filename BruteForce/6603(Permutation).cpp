#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}

		vector<int> a(k);

		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}

		vector<int> d;

		for (int i = 0; i < k - 6; i++) {
			d.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			d.push_back(1);
		}

		vector<vector<int>> ans;

		do {
			vector<int> current;
			for (int i = 0; i < k; i++) {
				if (d[i] == 1) {
					current.push_back(a[i]);
				}
			}

			ans.push_back(current);
		} while (next_permutation(d.begin(),d.end()));

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}