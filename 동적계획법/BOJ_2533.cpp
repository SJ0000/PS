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

const int INF = 1000000000;
const int MAXN = 1000000;
vector<int> adj[MAXN], child[MAXN];
bool check[MAXN];
int N, dp[MAXN][2]; // dp[i][0] = i가 early일때

//graph -> tree
void dfs(int now) {
	check[now] = true;
	for (int next : adj[now]) {
		if (!check[next]) {
			child[now].push_back(next);
			dfs(next);
		}
	}
}

int sns(int curr, bool pe) { // pe==true 면 부모가 얼리어댑터
	int &ret = dp[curr][pe];
	if (ret != -1) return ret;

	int notpick = INF, pick = 1;

	// 부모가 얼리어답터가 아니면 자식은 모두 얼리어답터야 한다.
	//즉 이번 정점(Next의 부모 , curr)는 얼리어답터여야 한다.
	for (int next : child[curr]) {
		pick += sns(next, true);
	}

	// 부모가 얼리어답터이면 자식은 얼리어답터가 아니어야 한다.
	if (pe) { 
		notpick = 0;
		for (int next : child[curr]) {
			notpick += sns(next, false);
		}
	}

	return ret = min(notpick, pick);
}

int main()
{	
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	
	memset(dp, -1, sizeof(dp));

	printf("%d\n",sns(0,true)); // 루트는 부모가 얼리어답터라고 가정.

	return 0;
}