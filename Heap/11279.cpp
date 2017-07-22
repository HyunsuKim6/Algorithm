#include <iostream>
#include <algorithm>

using namespace std;

int hn = 1;
int heap[100010];

void insert(int n) {
	heap[hn] = n;
	for (int i = hn; i/2 >= 1; i /= 2) {
		if (heap[i] > heap[i / 2]) {
			swap(heap[i], heap[i / 2]);
		}
	}
	hn += 1;
}

int pop() {
	int ret = heap[1];
	hn -= 1;
	heap[1] = heap[hn];
	heap[hn] = 0;
	for (int i = 1; i*2 <= hn;) {
		if (heap[i] > heap[2 * i] && heap[i] > heap[2 * i + 1]) {
			break;
		}
		else if (heap[2*i] > heap[2*i+1]) {
			swap(heap[i], heap[2 * i]);
			i = 2 * i;
		}
		else {
			swap(heap[i], heap[2 * i + 1]);
			i = 2 * i + 1;
		}
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (hn == 1) {
				cout << 0 << endl;
			}
			else {
				cout << pop() << endl;;
			}
		}
		else {
			insert(x);
		}
	}
	return 0;
}