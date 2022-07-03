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

//mid��ŭ �¸��� �߰����� �� Z�� 1% �̻� ������ t,�ƴϸ� f

// x�� �����ؼ� y�� �̰��� �� �·� (�Ҽ��� ����)
long long calc(long long x, long long y) {
	double ret = (y * 100) / x;
	return (long long)floor(ret);
}
//mid�� ���̰����� �·��� �ٲ�� t, �ƴϸ� f
bool simulate(long long mid) {
	//1���ڸ� �ȹٲ�°��
	if (Z == calc(N + mid, M + mid)) {
		return false;
	}
	else {
		return true;
	}
}

int getAns() {
	long long lo = 0, hi = 2000000000;
	// hi(�ִ�) �����̾ �Ұ����Ѱ��.
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