#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int a[16][16];
int visited[16][16];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
pair<int, int> st, ed;

void dfs(int x, int y) {
	int ax, ay;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax <= 15 && 0 <= ay && ay <= 15) {
			if (!visited[ax][ay]) {
				dfs(ax, ay);
			}
		}
	}
}

int main()
{
	int tc = 10;
	int trash;
	for (int T = 1; T <= tc; T++) {
		scanf("%d", &trash);
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		string s;
		for (int i = 0; i < 16; i++) {
			cin >> s;
			for (int j = 0; j < 16; j++) {
				a[i][j] = s[j] - '0';
				if (a[i][j] == 0) continue;
				if (a[i][j] == 1) visited[i][j] = true;
				if (a[i][j] == 2) {
					st = make_pair(i, j);
				}
				if (a[i][j] == 3) {
					ed = make_pair(i, j);
				}
			}
		}
		dfs(st.first, st.second);
		int ans;
		if (visited[ed.first][ed.second]) {
			ans = 1;
		}
		else {
			ans = 0;
		}
		printf("#%d %d\n", T, ans);
	}
	return 0;
}