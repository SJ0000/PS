#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

string dp[21][21][21][21][2]; 
bool check[21][21][21][21][2];

void dfs(int a,int b,int c,int d,int bit) {
	string &ret = dp[a][b][c][d][bit];
	if (check[a][b][c][d][bit]) return;
	check[a][b][c][d][bit] = true;
	if (a > 0 && bit == 0) {
		dfs(a - 1, b, c, d, 0);
		if (dp[a - 1][b][c][d][0].size() > 0) {
			ret = dp[a - 1][b][c][d][0] + "0";
			return;
		}
	}
	if (b > 0 && bit == 1) {
		dfs(a, b - 1, c, d, 0);
		if (dp[a][b - 1][c][d][0].size()) {
			ret = dp[a][b - 1][c][d][0] + "1";
			return;
		}
	}
	if (c > 0 && bit == 0) {
		dfs(a, b, c - 1, d, 1);
		if (dp[a][b][c - 1][d][1].size()) {
			ret = dp[a][b][c - 1][d][1] + "0";
			return;
		}
	}
	if (d > 0 && bit == 1) {
		dfs(a, b, c, d - 1, 1);
		if (dp[a][b][c][d - 1][1].size()) {
			ret = dp[a][b][c][d - 1][1] + "1";
			return;
		}
	}
}
int main()
{	
	int T;	
	cin >> T;
	dp[1][0][0][0][0] = "00";
	dp[0][1][0][0][1] = "01";
	dp[0][0][1][0][0] = "10";
	dp[0][0][0][1][1] = "11";
	int a, b, c, d;
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("#%d ", t);
		dfs(a, b, c, d, 0);
		dfs(a, b, c, d, 1);
		if (dp[a][b][c][d][0].size()) {
			cout << dp[a][b][c][d][0] << endl;
		}
		else if (dp[a][b][c][d][1].size()) {
			cout << dp[a][b][c][d][1] << endl;
		}
		else {
			cout << "impossible" << endl;
		}
	}
	return 0;
}