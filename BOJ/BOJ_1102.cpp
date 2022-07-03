#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int maxn = 16;
int cost[maxn][maxn];
bool state[maxn];
int dp[1 << maxn];
int n,p;

/* 
	그리디 안되는이유 
	ex) 1만 켜져있고 2,3,4,5를 켜야하는 경우.

	1번) 1->5 = 10 , 5->2 = 1, 2->3 = 1 , 3->4 = 1 이고
	2번) 1->2 = 5 , 2->3 = 5 , 3->4 = 5 , 4->5 = 5 이면

	그리디는 총 합이 13코스트인 1번루트 대신에 시작시에 작은값을 가진 2번루트로 진행하게 된다.
	따라서 dp로 풀어야 한다.
*/

// 현재상태가 ststus이고 num개를 가동중일때 추가로 발생하는 비용
int calcDp(int num, int status) { 
	if (num == p) {
		return 0;
	}
	int& ret = dp[status];
	if (ret != -1) return ret;

	ret = 987654321;

	// i->j
	for (int i = 0; i < n; i++) {
		//i가 켜져있는 경우
		if (status & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				// j가 꺼져있는경우.
				if (!(status & (1 << j))) {
					ret = min(ret, calcDp((num + 1), status | (1 << j)) + cost[i][j]);
				}
			}
		}
	}
	return ret;

}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	string state_str;
	cin >> state_str;

	int now = 0;
	int current = 0;
	for (int i = 0; i < state_str.size(); i++) {
		if (state_str[i] == 'Y') {
			current = current | (1 << i);
			now++;
		}
	}
	scanf("%d", &p);

	if (now == 0) { // 못키는경우
		if (p == 0) printf("0"); // 안켜도되는경우.
		else printf("-1"); // 못키는경우
	}
	else if (now >= p) { // 안켜도되는경우.
		printf("0");
	}
	else {
		printf("%d", calcDp(now, current));
	}

	return 0;
}