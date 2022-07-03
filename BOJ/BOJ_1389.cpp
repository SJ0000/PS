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

/*
	모든 간선의 cost가 1인 floyd 알고리즘
	촌수의 개념과 비슷하다.
*/

const int maxn = 101;
const int inf = 987654321;
int n, m;
int dist[maxn][maxn];

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void init() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			dist[i][j] = (i == j ? 0 : inf);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	int a, b;

	init();

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	floyd();

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += (dist[i][j]);
		}
		pq.push(make_pair(-1 * sum, -1 * i));
	}

	printf("%d\n", (-1 * pq.top().second) + 1);

	return 0;
}