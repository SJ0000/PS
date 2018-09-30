#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	long long n;
	for (int t_case = 1; t_case <= T; t_case++) {
		scanf("%lld", &n);
		printf("#%d %lld %lld %lld \n", t_case, n*(n + 1) / 2, n*n, n*(n + 1));
	}
	return 0;
}