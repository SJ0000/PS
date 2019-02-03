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
int a[maxn][maxn];
bool check[maxn][maxn];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m, k, cnt;
int answer = 0;


void dfs(int x, int y) {

	if (check[x][y]) return;
	check[x][y] = true;
	cnt++;

	int ax, ay;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax < n && 0 <= ay && ay < m) {
			dfs(ax, ay);
		}
	}
}
void init() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			a[i][j] = 0;
			check[i][j] = true;
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	int r, c;
	init();
	while (k-- > 0) {
		scanf("%d %d", &r, &c);
		a[r - 1][c - 1] = 1;
		check[r - 1][c - 1] = false; // 쓰레기는 접근가능
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 0;
			dfs(i, j);
			answer = max(answer, cnt);
		}
	}

	printf("%d\n", answer);

	return 0;
}