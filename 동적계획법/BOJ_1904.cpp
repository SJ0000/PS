#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

const int mod = 15746;
int dp[1000001];

void calc() {
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	calc();
	printf("%d\n", dp[n]);
	return 0;
}