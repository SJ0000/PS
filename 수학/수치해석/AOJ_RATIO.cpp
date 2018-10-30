#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

long long N, M, Z;

//mid만큼 승리를 추가했을 때 Z가 1% 이상 오르면 t,아니면 f

// x번 게임해서 y번 이겼을 때 승률 (소수점 버림)
long long calc(long long x, long long y) {
	double ret = (y * 100) / x;
	return (long long)floor(ret);
}
//mid번 더이겼을때 승률이 바뀌면 t, 아니면 f
bool simulate(long long mid) {
	//1의자리 안바뀌는경우
	if (Z == calc(N + mid, M + mid)) {
		return false;
	}
	else {
		return true;
	}
}

int getAns() {
	long long lo = 0, hi = 2000000000;
	// hi(최대) 연승이어도 불가능한경우.
	if (!simulate(hi)) {
		return -1;
	}
	long long m;
	while (lo + 1 < hi) {
		m = (lo + hi) / 2;
		if (simulate(m)) {
			hi = m;
		}
		else {
			lo = m;
		}
	}
	return hi;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &N, &M);
		Z = calc(N, M);
		cout << getAns() << endl;
	}
	return 0;
}