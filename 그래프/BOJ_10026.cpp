#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int maxn = 101;
char a[maxn][maxn];
bool check[maxn][maxn];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, ans1,ans2; // 1은 비색약 2는 색약


void dfs1(int x, int y) {
	
	if (check[x][y]) return;
	check[x][y] = true;
	char now = a[x][y];
	int ax, ay;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax < n && 0 <= ay && ay < n) {
			if (a[ax][ay] == now) {
				dfs1(ax, ay);
			}
		}
	}
}

void dfs2(int x, int y) { // r,g 묶어서
	if (check[x][y]) return;
	check[x][y] = true;
	char now = a[x][y];
	int ax, ay;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax < n && 0 <= ay && ay < n) {
			if (now == 'B') {
				if (a[ax][ay] == now) {
					dfs2(ax, ay);
				}
			}
			else {
				if (a[ax][ay] == 'R' || a[ax][ay] == 'G') {
					dfs2(ax, ay);
				}
			}
		}
	}
}

int main()
{	
	scanf("%d", &n);
	string s;
	ans1 = ans2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				dfs1(i, j);
				ans1++;
			}			
		}
	}

	memset(check, false, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				dfs2(i, j);
				ans2++;
			}
		}
	}
	printf("%d %d", ans1, ans2);

	return 0;
}