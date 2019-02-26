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
int N, dp[MAXN][2]; // dp[i][0] = i�� early�϶�

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

int sns(int curr, bool pe) { // pe==true �� �θ� �󸮾����
	int &ret = dp[curr][pe];
	if (ret != -1) return ret;

	int notpick = INF, pick = 1;

	// �θ� �󸮾���Ͱ� �ƴϸ� �ڽ��� ��� �󸮾���;� �Ѵ�.
	//�� �̹� ����(Next�� �θ� , curr)�� �󸮾���Ϳ��� �Ѵ�.
	for (int next : child[curr]) {
		pick += sns(next, true);
	}

	// �θ� �󸮾�����̸� �ڽ��� �󸮾���Ͱ� �ƴϾ�� �Ѵ�.
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

	printf("%d\n",sns(0,true)); // ��Ʈ�� �θ� �󸮾���Ͷ�� ����.

	return 0;
}