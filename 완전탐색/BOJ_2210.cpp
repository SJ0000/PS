#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

set<int> myset;
int a[5][5];
int N = 5;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int cnt, int num) {

	int now_n = num * 10;
	now_n += a[x][y];
	int now_cnt = cnt + 1;
	if (cnt == 6) {
		myset.insert(num);
		return;
	}
	int ax, ay;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax < N && 0 <= ay && ay < N) {
			dfs(ax, ay, now_cnt, now_n);
		}
	}
}
int main() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dfs(i, j, 0, 0);
		}
	}

	printf("%d\n", myset.size());



	return 0;
}