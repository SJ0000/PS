#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;
long long dp[101];
/* ex ) dp[5] =>
dp[0] + �ú��ٺٺ� = dp[0]*4;
dp[1] + �ú��ٺ� = dp[1]*3;
dp[2] + �ú��� = dp[2]*2;

-> dp[i] = max(dp[i-j]*(j-1)); (j�� �ּ� 3)
*/
void simulate() {
	//A�������°��
	for (int i = 0; i <= 100; i++) {
		dp[i] = i;
	}
	//�����ϴ°��
	for (int i = 5; i <= 100; i++) {
		for (int j = 3; j <= 5; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}
}
int main()
{
	scanf("%d", &N);
	simulate();
	printf("%lld\n", dp[N]);
	return 0;
}