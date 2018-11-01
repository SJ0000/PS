#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <float.h>

using namespace std;

vector<pair<int, int>> g[1001]; // <가중치,정점>

int N, M, V, E, st;
int min_dist[1001];
bool check[1001];
vector<int> fire;
//priority_queue는 내림차순으로 정렬하기때문에 
// dijkstra알고리즘에서 작은 값을 먼저 꺼내기 위해 가중치에 -를 붙힌다.

const int MAX_VALUE = 987654321;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	min_dist[st] = 0;
	int nowv, nextv, noww, nextw, nextDist;
	pq.push(make_pair(0, st));
	while (!pq.empty()) {
		nowv = pq.top().second;
		noww = -1 * pq.top().first;
		pq.pop();
		if (check[nowv]) continue;
		check[nowv] = true;

		sort(g[nowv].begin(), g[nowv].end());

		for (pair<double, int> node : g[nowv]) {
			nextv = node.second;
			nextw = node.first;
			// nextDist : st~nextv까지의 길이 -> st~nowv 까지의 길이가 noww, nowv~nextv 까지의 길이가 nextw
			nextDist = noww + nextw;
			//갱신
			if (min_dist[nextv] > nextDist) {
				min_dist[nextv] = nextDist;
				pq.push(make_pair(-nextDist, nextv));
			}
		}
	}
}

int main()
{
	int tc = 0;
	scanf("%d", &tc);
	while (tc-- > 0) {
		scanf("%d %d %d %d", &V, &E, &N, &M);
		st = 0;
		int u, v, w;

		for (int i = 0; i <= V; i++) {
			min_dist[i] = MAX_VALUE;
			g[i].clear();
			check[i] = false;
		}
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &u, &v, &w);
			g[u].push_back(make_pair(w, v));
			g[v].push_back(make_pair(w, u));
		}
		fire.clear();
		int val;
		for (int i = 0; i < N; i++) {
			scanf("%d", &val);
			fire.push_back(val);
		}
		//가상의 점.
		for (int i = 0; i < M; i++) {
			scanf("%d", &val);
			g[0].push_back(make_pair(0, val));
			g[val].push_back(make_pair(0, 0));
		}

		dijkstra();
		int ret = 0;
		for (int x : fire) {
			ret += min_dist[x];
		}
		printf("%d\n", ret);
	}
	return 0;
}