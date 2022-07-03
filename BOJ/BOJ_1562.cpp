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
int dp[maxn][10][full+1]; // dp[���� �ڸ���][�������ڸ��� ����][check(bitmask)] 
// dp[a][b][c] : a�ڸ��̸鼭 ������ ���� b�̰� check�� c�� ������ '����'
int main()
{
	scanf("%d", &n);	
	//1�ڸ�
	for (int i = 1; i < 10; i++) {
		dp[1][i][0 | (1 << i)] = 1;
	}
	//2�ڸ� ~ n�ڸ�
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= full; k++) {
				//0�� �������ڰ� 1�϶��� , 9�� �������ڰ� 8�϶���
				if (j == 0) {
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				}
				else if (j == 9) {
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				}
				else { //������
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}
	//����
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n][i][full]) % mod;
	}
	printf("%d", ans);
	return 0;
}