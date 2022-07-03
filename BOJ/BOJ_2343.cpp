#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int l[100001];
int n, m;
int simulate(long long cap) {
	int ret = 1;
	long long now = 0;
	for (int i = 0; i < n; i++) {
		//불가능한경우.
		if (l[i] > cap) {
			return 0;
		}
		if (now + l[i] <= cap) {
			now += l[i];
		}
		else {
			now = l[i];
			ret++;
		}
	}
	return ret;
}

//불만족하는경우 l,만족하는경우 r.
void calc() {
	long long l = 0, r = 1000000000;
	long long mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		//용량이 mid일때 필요한 블루레이의 개수.
		int br_n = simulate(mid);
		//mid의 용량으로 저장이 불가능하거나
		//블루레이 개수가 모자라는경우.
		if (br_n == 0 || br_n > m) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf("%lld\n", r);
}


int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}
	calc();
	return 0;
}