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

const int MAXN = 101;
const int INF = 987654321;
int dist[MAXN][MAXN];
int n;

void init() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dist[i][j] = (i == j ? 0 : INF);
		}
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}


int main()
{
	int a, b, t, x, y;
	init();
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		dist[x][y] = 1;
		dist[y][x] = 1;
	}
	floyd();
	printf("%d\n", dist[a][b] == INF ? -1 : dist[a][b]);
	return 0;
}