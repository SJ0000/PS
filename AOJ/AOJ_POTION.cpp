#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int N;
int r[201], p[201];

int gdc(int a, int b) {
	return b == 0 ? a : gdc(b, a%b);
}
//�м� a/b���� ���ų� ū �ּ��� �ڿ���
int integerCeil(int a, int b) {
	return (a + b - 1) / b;
}

vector<int> calc() {
	vector<int> ret;
	int a, b, x, y;
	double maxRatio = 0, nowRatio;
	//maxRatio�� ���Ѵ�.
	for (int i = 0; i < N; i++) {
		nowRatio = (double)p[i] / (double)r[i];
		if (maxRatio < nowRatio) {
			a = p[i];
			b = r[i];
			maxRatio = nowRatio;
		}
	}
	// r[i]�� �ִ����� x�� ���Ѵ�.
	x = r[0];
	for (int i = 1; i < N; i++) {
		x = gdc(x, r[i]);
	}
	y = x;
	// a/b * x <= y �� �����ϴ� y�� ���Ѵ�.
	y = integerCeil(a*x, b);

	// x/y�� �ǵ��� �����ش�.
	// p[i] + ret[i] = r[i]*x/y
	// -> ret[i] = r[i]*x/y - p[i]
	for (int i = 0; i < N; i++) {
		ret.push_back((r[i] * y / x) - p[i]);
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &r[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &p[i]);
		}
		vector<int> ans = calc();
		for (int i = 0; i < N; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");

	}
	return 0;
}