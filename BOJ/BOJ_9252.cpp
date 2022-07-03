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

string a, b;

const int MAX = 1001;
int m,n; // a,b,의 size
int dp[MAX][MAX]; // dp[x][y] = a의 x번째, b의 y번째까지 LCS의 길이.

int main()
{	
	cin >> a;	a = '0' + a;
	cin >> b;	b = '0' + b;

	m = a.size();
	n = b.size();
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			//같은문자인경우 : 이전 lcs길이 +1
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				//다른문자인 경우 : 이전값 비교
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
	//		printf("a[%d] = %c , b[%d] = %c , dp[%d][%d] = %d \n", i, a[i], j, b[j], i, j, dp[i][j]);

		}
	}
	//문자 찾기.
	string ans = "";
	int lcsIdx = dp[m - 1][n - 1];
	for (int i = m-1; i > 0; i--) {
		for (int j = n - 1; j > 0; j--) {
			if (dp[i][j] == lcsIdx && dp[i][j - 1] == lcsIdx - 1 && dp[i - 1][j] == lcsIdx - 1) {
				lcsIdx--;
				ans = a[i] + ans;
				break;
			}
		}
		if (lcsIdx == 0) break;
	}
	cout << dp[m - 1][n - 1] << endl;
	cout << ans << endl;
	return 0;
}