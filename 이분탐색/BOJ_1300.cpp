#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;

long long N, K;


void bSearch() {
	//lo 불가능, hi 가능

	if (K == 1) {
		printf("1");
		return;
	}

	long long lo, hi, mid, cnt;
	lo = 1, hi = 1000000000;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		//		printf("lo hi mid cnt : %lld %lld %lld %lld\n", lo, hi, mid, cnt);

		if (cnt >= K) { // hi가 가능이니까 cnt가 k보다 같거나 클때 hi = mid
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	printf("%lld\n", hi);
}

int main()
{
	scanf("%lld %lld", &N, &K);
	bSearch();
	return 0;
}