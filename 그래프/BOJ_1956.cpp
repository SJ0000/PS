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

int v, e;
const int MAXV = 401;
const int INF = 987654321;
int dist[MAXV][MAXV];

void init() {

	for (int i = 0; i < MAXV; i++) {
		for (int j = 0; j < MAXV; j++) {
			dist[i][j] = INF;
		}
	}

}

void floyd() {

	for (int k = 1; k <= v; k++) {

		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}

	}
}


int main()
{
	scanf("%d %d", &v, &e);

	int a, b, c;
	init();
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
	}
	floyd();
	int minCycleLen = INF;
	for (int i = 1; i <= v; i++) {
		minCycleLen = min(minCycleLen, dist[i][i]);
	}
	printf("%d\n", minCycleLen == INF ? -1 : minCycleLen);

	return 0;
}