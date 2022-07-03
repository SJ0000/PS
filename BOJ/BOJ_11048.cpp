#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
using namespace std;

int a[1001][1001];
int dp[1001][1001];
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
int n, m;

int main()
{	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = a[0][0];
	int ax, ay;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				ax = i + dx[k]; ay = j + dy[k];
				dp[ax][ay] = max(dp[ax][ay], dp[i][j] + a[ax][ay]);
			}			
		}
	}	
	printf("%d\n", dp[n - 1][m - 1]);
	return 0;
}