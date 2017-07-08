#include <iostream>
#include <math.h>

using namespace std;

int check[1000000] = { 0 };
int Answer;
int P;
int cnt;

void dfs(int node) {
	int next = 0;

	check[node] = ++cnt;

	while (node != 0) {
		next += pow(node % 10, P);
		node /= 10;
	}

	if (check[next] > 0) {
		Answer = check[next]-1;
		return;
	}

	dfs(next);
}

int main() {
	freopen("Text.txt", "r", stdin);

	int A;

	cin >> A >> P;

	dfs(A);

	cout << Answer << endl;

	return 0;
}