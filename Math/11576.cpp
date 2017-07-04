#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	//freopen("Text.txt", "r", stdin);

	int A, B, num, input;
	int result = 0;
	int tmp = 1;
	int Answer[30];

	cin >> A >> B;

	cin >> num;

	while (num--) {
		cin >> input;
		tmp = input * pow(A, num);
		result += tmp;
	}

	int i = 0;

	while (result > 0) {
		tmp = result%B;		
		Answer[i] = tmp;
		i++;
		result /= B;
	}

	for (int j = i-1; j >= 0; j--) {
		cout << Answer[j] << " ";
	}

}