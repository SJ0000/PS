#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
int M, N; 	//M세로 N가로
int a[501][501];
int dp[501][501];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int dfs(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 0 && y == 0) return 1;
	if (!(0 <= x && x < M && 0 <= y && y < N)) return 0; // (1)
	int ax, ay;
	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (a[ax][ay] > a[x][y]) {
			// (2)
			dp[x][y] += dfs(ax, ay);
		}
	}
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(M - 1, N - 1));
	return 0;
}