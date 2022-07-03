#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;

//"상자 앞에서부터 넣었을 때"


int N, K, D;
int rule[10001][3]; // A,B,C;

void binarySearch() {
	//lo는 불가능, hi는 가능
	int lo, hi, mid;
	long long cnt;
	lo = 1, hi = N;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) {
			//mid가 i번 규칙의 끝보다 작은 경우
			//전부 넣을수있음.
			if (rule[i][1] < mid) {
				cnt += (rule[i][1] - rule[i][0]) / rule[i][2] + 1;
			}
			else if (rule[i][0] == mid) {
				//mid가 i번 규칙의 시작점인 경우.
				//시작점에 1개 넣을수있다.
				cnt++;
			}
			else if (rule[i][0] > mid) {
				//mid가 시작점보다 작은경우
				//도토리 못넣음
				continue;
			}
			else {
				//나머지, 시작점과 끝점 중간인경우
				cnt += (mid - rule[i][0]) / rule[i][2] + 1;
			}
		}
		//가능한경우
		if (cnt >= D) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	printf("%d\n", hi);
}

int main()
{
	scanf("%d %d %d", &N, &K, &D);
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &rule[i][0], &rule[i][1], &rule[i][2]);
	}
	binarySearch();

	return 0;
}