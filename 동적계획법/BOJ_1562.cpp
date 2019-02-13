#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int mod = 1000000000;
const int maxn = 101;
const int full = (1 << 10) - 1;
int n;
int dp[maxn][10][full+1]; // dp[현재 자리수][마지막자리의 숫자][check(bitmask)] 
// dp[a][b][c] : a자리이면서 마지막 수가 b이고 check가 c인 숫자의 '개수'
int main()
{
	scanf("%d", &n);	
	//1자리
	for (int i = 1; i < 10; i++) {
		dp[1][i][0 | (1 << i)] = 1;
	}
	//2자리 ~ n자리
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= full; k++) {
				//0은 이전숫자가 1일때만 , 9는 이전숫자가 8일때만
				if (j == 0) {
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				}
				else if (j == 9) {
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				}
				else { //나머지
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}
	//정답
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n][i][full]) % mod;
	}
	printf("%d", ans);
	return 0;
}