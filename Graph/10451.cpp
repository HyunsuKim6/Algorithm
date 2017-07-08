#include <iostream>
#include <vector>

using namespace std;

int N;
int a[1003];
vector<int> v[1003];
bool check[1003];
bool flag = false;
int cnt = 0;

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (check[next] == 1) {
			flag = true;
			cnt++;
		}
		if (flag) {
			break;
		}
		dfs(next);
	}
}

int main() {
	
	freopen("Text.txt", "r", stdin);

	int T;

	cin >> T;

	while (T--) {
		cnt = 0;
		flag = false;

		cin >> N;

		for (int i = 1; i <= N; i++) {
			check[i] = 0;
			v[i].clear();
		}

		for(int i = 1; i <= N; i++) {
			cin >> a[i];
		}

		for (int i = 1; i <= N; i++) {
			v[i].push_back(a[i]);
		}

		for (int i = 1; i <= N; i++) {
			flag = false;
			if (check[i] == false)
				dfs(i);
		}

		cout << cnt << endl;
	}

	return 0;
}