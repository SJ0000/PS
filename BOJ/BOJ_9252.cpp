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
int m,n; // a,b,�� size
int dp[MAX][MAX]; // dp[x][y] = a�� x��°, b�� y��°���� LCS�� ����.

int main()
{	
	cin >> a;	a = '0' + a;
	cin >> b;	b = '0' + b;

	m = a.size();
	n = b.size();
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			//���������ΰ�� : ���� lcs���� +1
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				//�ٸ������� ��� : ������ ��
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
	//		printf("a[%d] = %c , b[%d] = %c , dp[%d][%d] = %d \n", i, a[i], j, b[j], i, j, dp[i][j]);

		}
	}
	//���� ã��.
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