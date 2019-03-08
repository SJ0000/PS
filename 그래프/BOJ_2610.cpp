#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>

using namespace std;

const int MAXN = 101;
const int INF = 987654321;
int n, m;
int dist[MAXN][MAXN];
bool check[MAXN];
//플로이드로 전체 길이 구하고
//dfs로 묶어서 구하기

void init() {
	for (int i = 0; i < MAXN; i++) {
		check[i] = false;
	}
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dist[i][j] = (i == j ? 0 : INF);
		}
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void calc() {

	vector<int> ansList;
	vector<int> sets;
	for (int i = 1; i <= n; i++) {
		//집합 하나 구하기
		if (check[i]) continue;
		sets.clear();
		sets.push_back(i);
		check[i] = true;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF && i!=j) {
				sets.push_back(j);
				check[j] = true;
			}
		}
		//계산
		int maxReqTime = INF;
		int ans = 0;
		int nowReqTime;
		for (int now : sets) {			
			nowReqTime = -1;
			for (int next : sets) {
				nowReqTime = max(nowReqTime, dist[now][next]);
			}
	//		printf("%d's max : %d\n", now, nowReqTime);
			if (nowReqTime < maxReqTime) {
				ans = now;
				maxReqTime = nowReqTime;
			}
		}
		ansList.push_back(ans);
	}
	sort(ansList.begin(), ansList.end());
	printf("%d\n", ansList.size());
	for (int now : ansList) {
		printf("%d\n", now);
	}

}

int main()
{	
	scanf("%d %d", &n, &m);
	//관계
	int a, b;
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	floyd();
	calc();

	return 0;
}