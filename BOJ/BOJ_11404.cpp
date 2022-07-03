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

const int maxn = 101;
const int maxv = 987654321;
int n, m; // 도시, 버스
int dist[maxn][maxn];

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
	scanf("%d %d", &n, &m);
	int a, b, c;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = maxv;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c); //주의
	}
	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dist[i][j] == maxv ? 0 : dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}