#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, M, K;
int a, b, c;
long long psum[1000001];
int num[1000001];
int upd[1000001];
vector<int> updater;
void update(int x, int c) {
	//x번째 수를 c로 바꾼다.

	if (upd[x] == 0) {
		updater.push_back(x);
	}
	int diff = c - num[x];
	num[x] = c;
	upd[x] += diff;
	//psum update	
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	//N개 수 입력받기
	int val;
	scanf("%d", &val);
	psum[0] = val;
	num[0] = val;
	memset(upd, 0, sizeof(upd));
	for (int i = 1; i < N; i++) {
		scanf("%d", &val);
		psum[i] = psum[i - 1] + val;
		num[i] = val;
	}
	long long ans;
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {
			//b번째 수를 c로 바꾼다.
			update(b - 1, c);
		}
		else {
			if (b == 1) {
				ans = psum[c - 1];
				//update반영
				for (int x : updater) {
					if (b - 1 > x || c - 1 < x) continue;
					ans += upd[x];
				}
				printf("%lld\n", ans);
			}
			else {
				ans = psum[c - 1] - psum[b - 2];
				for (int x : updater) {
					if (b - 1 > x || c - 1 < x) continue;
					ans += upd[x];
				}
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}