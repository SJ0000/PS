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

const int maxn = 126;
const int maxv = 987654321;
int n;
int cave[maxn][maxn];
int dist[maxn][maxn]; // 0,0 에서 i,j로 가는 최소비용.
bool check[maxn][maxn];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dijkstra() {

	priority_queue<pair<int, int>> pq; // greater대신 value를 -로 저장

	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			dist[i][j] = maxv;
			check[i][j] = false;
		}
	}

	dist[0][0] = cave[0][0];
	pq.push(make_pair(-1 * dist[0][0], 0));

	int nowx, nowy, nowv, nextx, nexty, nextv, nextDist;
	while (!pq.empty()) {
		nowx = pq.top().second / 1000;
		nowy = pq.top().second % 1000;
		nowv = -1 * pq.top().first;
		check[nowx][nowy] = true;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			nextx = nowx + dx[i];
			nexty = nowy + dy[i];
			if (0 <= nextx && nextx < n && 0 <= nexty && nexty < n) {
				if (!check[nextx][nexty]) {
					nextv = cave[nextx][nexty];
					nextDist = nowv + nextv;
					if (dist[nextx][nexty] > nextDist) {
						dist[nextx][nexty] = nextDist;
						pq.push(make_pair(-1 * nextDist, nextx * 1000 + nexty));
					}
				}
			}
		}
	}
}

int main()
{
	int tc = 1;
	while (true) {

		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &cave[i][j]);
			}
		}
		//dijkstra
		dijkstra();
		printf("Problem %d: %d\n", tc++, dist[n - 1][n - 1]);
	}

	return 0;
}