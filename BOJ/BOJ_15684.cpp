#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int n, m, h;
int l[31][11];
int ans;
//picked �� ����, x = ����� �ϴ���.
void dfs(int picked, int x) {
	//Base 1 : ���� ������ ���
	if (ans > 0) {
		return;
	}		
	//Base 2 : ������ �Ϸ�� ���
	if (picked == x) {
		for (int i = 1; i <= n; i++) {
			int now = i;
			for (int j = 1; j <= h; j++) {
				if (l[j][now] != 0) {
					now += l[j][now];
				}
			}
			if (now != i) {
				return;
			}
		}
		ans = x;
		return;
	}
	//pick
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n-1; j++) {
			if (l[i][j] == 0 && l[i][j+1]==0) {
				l[i][j] = 1;
				l[i][j + 1] = -1;
				dfs(picked + 1, x);
				l[i][j] = 0;
				l[i][j + 1] = 0;
				continue;
			}
		}
	}
}
int main()
{		
	int a, b;
	ans = -1;
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		l[a][b] = 1;
		l[a][b + 1] = -1;
	}
	for (int i = 0; i <= 3; i++) {
		dfs(0, i);
		if (ans >=0) {
			break;
		}
	}
	printf("%d", ans);
	return 0;
}