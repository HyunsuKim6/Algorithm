#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<int> s;
	
	int n;
	cin >> n;
	while (n--) {
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	
	int m;
	cin >> m;
	while (m--) {
		int x;
		scanf("%d",&x);
		printf("%d ", s.count(x));
	}
	return 0;
}