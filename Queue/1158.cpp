#include <iostream>
#include <queue>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	int n, m, a;
	queue<int> q;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	for(int i = 0 ; i< n-1; i++) {
		for (int i = 0; i < m - 1; i++) {
			a = q.front();
			q.pop();
			q.push(a);
		}
		cout << q.front()<< ", ";
		q.pop();
	}
	cout << q.front() << ">" << endl;
	return 0;
}
