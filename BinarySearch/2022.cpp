#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	double x, y, c;
	while (cin >> x >> y >> c) {
		double l = 0;
		double r = min(x, y);
		double d = 0;
		while (abs(l - r) > 1e-6) {
			d = (l + r) / 2;
			double h1 = sqrt(x*x - d*d);
			double h2 = sqrt(y*y - d*d);
			double h = h1*h2 / (h1 + h2);

			if (h > c) {
				l = d;
			}
			else {
				r = d;
			}
		}

		printf("%0.3f\n", d);
	}
}