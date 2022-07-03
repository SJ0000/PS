#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int dp[10001];
int val;
int main()
{	
	int t;
	scanf("%d %d", &t,&val);
	int coin;
	for (int i = 0; i < 10001; i++) {
		dp[i] = 10001;
	}
	while (t-- > 0) {
		scanf("%d", &coin);
		if (coin > 10000) continue;
		dp[coin] = 1;
	}
	int tmp;
	for (int i = 1; i <= val; i++) {
		if (dp[i] == 1) continue;
		for (int j = 1; j <= i/2; j++) {
			tmp = dp[j] + dp[i - j];
			dp[i] = min(dp[i], tmp);
		}
	}
	if (dp[val] == 10001) {
		printf("%d\n",-1);
	}
	else {
		printf("%d\n", dp[val]);
	}
	return 0;
}