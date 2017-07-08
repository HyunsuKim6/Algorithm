#include <iostream>

using namespace std;

int a[30][2];

void preorder(int m) {
	if (m == -1) {
		return;
	}
	cout << (char)(m + 'A');
	preorder(a[m][0]);
	preorder(a[m][1]);
}

void inorder(int m) {
	if (m == -1) {
		return;
	}
	inorder(a[m][0]);
	cout << (char)(m + 'A');
	inorder(a[m][1]);
}

void postorder(int m) {
	if (m == -1) {
		return;
	}
	postorder(a[m][0]);
	postorder(a[m][1]);
	cout << (char)(m + 'A');
}

int main() {
	freopen("Text.txt", "r", stdin);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		char input,left,right;
		cin >> input;
		int m = input - 'A';
		
		cin >> left;
		if (left == '.') {
			a[m][0] = -1;
		}
		else {
			a[m][0] = left - 'A';
		}

		cin >> right;
		if (right == '.') {
			a[m][1] = -1;
		}
		else {
			a[m][1] = right - 'A';
		}
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
}