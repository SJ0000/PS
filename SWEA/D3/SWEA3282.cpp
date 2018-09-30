#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int>> knapsack; //부피,가치
int dp[1001][1001];
int main(void) {
	int T;
	scanf("%d", &T);
	int v, c;
	for (int t_case = 1; t_case <= T; t_case++) {
		knapsack.clear();
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &v, &c);
			knapsack.push_back(make_pair(v, c));
		}
		//d[i][j] = i번째 까지 왔을때 무게제한이 j
		int nv, nw;// now_value , now_weight;
		//0번째는 그냥 채우고 1번째부터 검사.
		nv = knapsack[0].second;
		nw = knapsack[0].first;
		for (int j = 0; j <= k; j++) {
			if (j < nw) {
				continue;
			}
			dp[0][j] = nv;
		}
		for (int i = 1; i < n ; i++) {
			nv = knapsack[i].second;
			nw = knapsack[i].first;
			for (int j = 0; j <= k ; j++) {		
				// 안고르는 경우 : dp[i-1][j]
				dp[i][j] = dp[i - 1][j];
				if (j < nw) {
					continue;
				}
				// 고르는 경우 : dp[i-1][j-nw]+nv;
				dp[i][j] = max(dp[i][j], dp[i-1][j-nw] + nv);
			}
		}
		printf("#%d %d", t_case, dp[n - 1][k]);
	}
	return 0;
}