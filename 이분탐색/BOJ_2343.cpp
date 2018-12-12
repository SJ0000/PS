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
		//�Ұ����Ѱ��.
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

//�Ҹ����ϴ°�� l,�����ϴ°�� r.
void calc() {
	long long l = 0, r = 1000000000;
	long long mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		//�뷮�� mid�϶� �ʿ��� ��緹���� ����.
		int br_n = simulate(mid);
		//mid�� �뷮���� ������ �Ұ����ϰų�
		//��緹�� ������ ���ڶ�°��.
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