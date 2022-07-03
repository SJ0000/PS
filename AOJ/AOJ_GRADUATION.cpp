#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
const int INF = 987654321;
const int MAXN = 12;
int N, K, M, L;
int pre[MAXN]; // pre[i] = i번 과목의 선수과목의 집합
int classes[10]; //i번째 학기에 개설되는 과목의 집합.
int cache[10][1 << MAXN];

int bitCount(int n) {
	int ret = 0;
	for (int i = 0; i < MAXN; i++) {
		if (n & (1 << i)) ret++;
	}
	return ret;
}

//이번학기가 semester이고, 지금까지 들은 과목의 집합이 taken일때
//K개 이상의 과목을 모두 들으려면 몇 학기나 더 있어야 하는가?
//불가능한경우 inf반환.
int graduate(int semester, int taken) {

	//이미 k개 이상 들은 경우.
	if (bitCount(taken) >= K) {
		return 0;
	}
	//M학기가 지난경우,즉 불가능한 경우.
	if (semester == M) {
		return INF;
	}
	// dynamic
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;

	ret = INF;
	//이번학기에 개설된 과목 중 안들은 과목들의 집합.
	int canTake = (classes[semester] & ~taken);
	//선수과목 안들은거 걸러냄.
	for (int i = 0; i < N; i++) {
		// i번 과목에 대해 i번 과목을 수강하지 않았으면서
		// i의 선수과목 중 이수하지 않은 과목이 있는 경우.
		if (canTake & (1 << i) && (taken & pre[i]) != pre[i]) {
			canTake &= ~(1 << i); //i번 과목을 cantake에서 제거.
		}
	}
	//이 집합의 모든부분집합을 순회.
	for (int take = canTake; take > 0; take = ((take - 1)&canTake)) {
		//L과목 초과인 경우 무시
		if (bitCount(take) > L) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	//아무것도 안듣는 경우
	ret = min(ret, graduate(semester + 1, taken));

	return ret;
}



int main()
{
	int tc; scanf("%d", &tc);
	while (tc-- > 0) {
		memset(pre, 0, sizeof(pre));
		memset(cache, -1, sizeof(cache));
		memset(classes, 0, sizeof(classes));
		scanf("%d %d %d %d", &N, &K, &M, &L);
		int ncnt, val;
		for (int i = 0; i < N; i++) {
			scanf("%d", &ncnt);
			for (int j = 0; j < ncnt; j++) {
				scanf("%d", &val);
				pre[i] |= (1 << val);
			}
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &ncnt);
			for (int j = 0; j < ncnt; j++) {
				scanf("%d", &val);
				classes[i] |= (1 << val);
			}
		}
		int ans = graduate(0, 0);
		if (ans == INF) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}