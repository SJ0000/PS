#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>
using namespace std;

int build[1000];
int N;

int simulate() {
	int ret = 0;
	int near_m = -1;
	int lmax, rmax;
	int height;
	for (int i = 2; i <= N - 2; i++) {
		height = build[i];
		lmax = max(build[i - 1], build[i - 2]);
		rmax = max(build[i + 1], build[i + 2]);
		near_m = max(lmax, rmax);
		if (near_m < height) {
			ret += (height - near_m);
		}
	}
	return ret;
}

int main(void) {
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &build[i]);
		}
		printf("#%d %d\n", tc, simulate());
	}
	return 0;
}