#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, k;
int a[9][9];
bool check[9][9];
vector<int> st; // start 할수있는 주소 저장.
int max_length;
void dfs(int x, int y, int now_length, bool isBuilded) {
	if (check[x][y]) {
		return;
	}
	check[x][y] = true;
	max_length = max(max_length, now_length);
	int ax, ay;
	int deep = 0;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax < n && 0 <= ay && ay < n) {
			if (!check[ax][ay]) {
				if (a[ax][ay] < a[x][y]) {
					//그냥 갈수있는 경우 그냥 간다.
					dfs(ax, ay, now_length + 1, isBuilded);
				}
				else if (!isBuilded && a[ax][ay] - k < a[x][y]) {
					//깎아서 갈수 있는 경우 일단깎고 다시복구				
					//무조건 k만큼 깎는게 아니라 적게깎아야 이득
					//얼마나깎을지 결정한다.
					deep = a[ax][ay] - a[x][y] + 1;
					a[ax][ay] -= deep;
					dfs(ax, ay, now_length + 1, true);
					a[ax][ay] += deep;
				}
			}
		}
	}
	check[x][y] = false;
}
int main(void) {
	int T;
	scanf("%d", &T);
	int high;
	int stx, sty;
	for (int t_case = 1; t_case <= T; t_case++) {
		st.clear(); 
		max_length = 0;
		scanf("%d %d", &n, &k);		
		high = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				high = max(high, a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == high) {
					st.push_back(i * 10 + j);
				}
			}
		}
		for (int pos : st) {
			memset(check, false, sizeof(check));
			stx = pos / 10;
			sty = pos % 10;
			dfs(stx, sty, 1, false);
		}
		printf("#%d %d\n", t_case, max_length);
	}
	return 0;
}