#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int N;
int a[101][101];
bool c[101][101][101]; // c[h][i][j] h만큼 잠겼을때 i,j;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int maxh;

void dfs(int h, int x, int y) {
	c[h][x][y] = true;
	int ax, ay;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];
		if (0 <= ax && ax < N && 0 <= ay && ay < N) {
			if (!c[h][ax][ay]) {
				dfs(h, ax, ay);
			}
		}
	}
}

int main(void) {


	scanf("%d", &N);
	maxh = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
			maxh = max(maxh, a[i][j]);
		}
	}


	for (int h = 0; h <= maxh; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] <= h) {
					c[h][i][j] = true;
				}
			}
		}
	}
	int ans = 0;
	int tmp = 0;
	for (int h = 0; h <= maxh; h++) {
		tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!c[h][i][j]) {
					dfs(h, i, j);
					tmp++;
				}
			}
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);

	return 0;
}
