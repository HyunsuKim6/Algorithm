#include <iostream>

using namespace std;

int main() {
	char oper[10];
	int n,m;
	int set = 0;

	cin >> n;

	while (n--) {
		scanf("%s", &oper);

		if (oper[0] == 'a'&&oper[1] == 'd') {
			scanf("%d", &m);
			set |= (1 << m);
		}
		else if (oper[0] == 'r') {
			scanf("%d", &m);
			set &= ~(1 << m);
		}
		else if (oper[0] == 'c') {
			scanf("%d", &m);
			if (set&(1 << m)) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
		}
		else if (oper[0] == 't') {
			scanf("%d", &m);
			set ^= (1 << m);
		}
		else if (oper[0] == 'a'&&oper[1] == 'l') {
			set = (1 << 21) - 1;
		}
		else if (oper[0] == 'e') {
			set = 0;
		}
	}
}