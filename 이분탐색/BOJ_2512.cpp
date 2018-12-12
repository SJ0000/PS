#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int offer[10001];
long long max_budget;
long long total_budget;
int n, max_offer;

void calc() {
	//1) 모든 요청을 수용 가능한 경우.
	if (total_budget <= max_budget) {
		printf("%d", max_offer);
		return;
	}
	//2) 상한액을 두어야 하는 경우.
	int l = 0, r = 100000;
	long long now;
	int mid;
	//최적의 now를 계산
	while (l <= r) {
		mid = (l + r) / 2;
		now = 0;
		//상한액을 mid로 설정하고 simulation;
		for (int i = 0; i < n; i++) {
			if (offer[i] <= mid) {
				now += offer[i];
			}
			else {
				now += mid;
			}
		}
		if (now == max_budget) {
			break;
		}
		else if (now > max_budget) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
		//	printf("l : %d r : %d mid : %d  now : %lld\n", l,r ,mid, now);
	}
	if (now > max_budget) {
		mid--;
	}
	printf("%d\n", mid);
}

int main()
{
	scanf("%d", &n);
	total_budget = 0;
	max_offer = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &offer[i]);
		total_budget += offer[i];
		max_offer = max(max_offer, offer[i]);
	}
	scanf("%lld", &max_budget);
	calc();
	return 0;
}