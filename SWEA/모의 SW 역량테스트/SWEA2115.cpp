#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M, C;
int a[11][11];
int max_honey;
bool rangeCheck(int fc, int sc) {
	int tx = fc  100; int ty = fc % 100;
	int rx = sc  100; int ry = sc % 100;	
	겹치는 경우.
	if ((tx == rx)) {
		if ((ty = ry) && (ry = ty + M - 1)) {
			return false;
		}
		if ((ry = ty) && (ty = ry + M - 1)) {
			return false;
		}
	}
	범위를 벗어나는 경우.
	if (ty + M   N  ry + M  N) {
		return false;
	}
	return true;
}
int getMax(vectorint h) {
	Greedy X  완전탐색.
	int ret = 0;
	1개 고르는것부터 M개 고르는것까지..
	BitMask로 풀어보자.
	int limit,tmp;
	for (int i = 1; i  (1h.size()); i++) {
		limit = C;
		tmp = 0;
		for (int j = 0; j  h.size(); j++) {
			if (i & (1  j)) {
				limit -= h[j];
				tmp += h[j]  h[j];
			}
			if (limit  0) {
				tmp = -1;
				break;
			}
		}
		ret = max(tmp, ret);
	}	
	return ret;
}
first choice, second choice
해야할것.
선택 알고리즘 바꿔야함. 완전탐색으로.(getMax)
ex) C가 10이고 7 5 5 면 7하나 선택하는것보다 5 2개선택하는게 이득이기때문. 
void go(int fc, int sc) {
	if (!rangeCheck(fc, sc)) return;

	int tx = fc  100; int ty = fc % 100;
	int rx = sc  100; int ry = sc % 100;
	vectorint honey;
	int myHoney = 0;
	for (int st = ty; st  ty + M; st++) {
		honey.push_back(a[tx][st]);
	}
	myHoney += getMax(honey);
	test
	printf(FC  %d %d max  %d  , tx, ty, myHoney);
	testEnd
	honey.clear();
	for (int st = ry; st  ry + M; st++) {
		honey.push_back(a[rx][st]);
	}	
	myHoney += getMax(honey);
	printf(SC  %d %d max  %d    TOTAL  %d n, rx, ry, getMax(honey),myHoney);
	max_honey = max(max_honey, myHoney);
}
int main(void) {
	int T;
	scanf(%d, &T);
	for(int t_case = 1; t_case = T; t_case++) {
		max_honey = -1;
		scanf(%d %d %d, &N, &M, &C);
		for (int i = 0; i  N; i++ ) {
			for (int j = 0; j  N; j++) {
				scanf(%d, &a[i][j]);
			}
		}
		for (int i = 0; i  N; i++) {
			for (int j = 0; j  N; j++) {

				for (int x = 0; x  N; x++) {
					for (int y = 0; y  N; y++) {
						go(i  100 + j, x  100 + y);
					}
				}

			}
		}
		printf(#%d %dn, t_case, max_honey);
	}
	return 0;
}