#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<string, int> m = { 
	{"black",0},{"brown",1},{"red",2},
	{"orange",3},{"yellow",4},{"green",5},
	{"blue",6},{"violet",7},{"grey",8},
	{"white",9} };

	string a;
	long long ans = 0;
	
	cin >> a;

	ans += 10 * m[a];
	
	cin >> a;

	ans += m[a];

	cin >> a;

	for (int i = 0; i < m[a]; i++) {
		ans *= 10;
	}

	cout << ans << endl;

	return 0;
}