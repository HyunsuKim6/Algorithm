#include <iostream>
#include <algorithm>

using namespace std;

long long a[5000000];

int main() {
	long long N, K;

	scanf("%lld %lld", &N, &K);

	for (long long i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}

	nth_element(a, a+K-1,a + N);

	printf("%lld\n",a[K - 1]);
	
	return 0;
}