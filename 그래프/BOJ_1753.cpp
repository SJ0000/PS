#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<pair<int, int>> g[20001]; // <����ġ,����>

int V, E, st;
int min_dist[20001];
bool check[20001];

//priority_queue�� ������������ �����ϱ⶧���� 
// dijkstra�˰��򿡼� ���� ���� ���� ������ ���� ����ġ�� -�� ������.

const int MAX_VALUE = 987654321;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	min_dist[st] = 0;
	int nowv, noww, nextv, nextw;
	int nextDist;
	pq.push(make_pair(0, st));
	while (!pq.empty()) {
		nowv = pq.top().second;
		noww = -1 * pq.top().first;
		pq.pop();
		if (check[nowv]) continue;
		check[nowv] = true;

		sort(g[nowv].begin(), g[nowv].end());

		for (pair<int, int> node : g[nowv]) {
			nextv = node.second;
			nextw = node.first;
			// nextDist : st~nextv������ ���� -> st~nowv ������ ���̰� noww, nowv~nextv ������ ���̰� nextw
			nextDist = noww + nextw;
			//����
			if (min_dist[nextv] > nextDist) {
				min_dist[nextv] = nextDist;
				pq.push(make_pair(-nextDist, nextv));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &st);
	int u, v, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= V; i++) {
		min_dist[i] = MAX_VALUE;
	}
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (min_dist[i] == MAX_VALUE) {
			printf("INF\n");
		}
		else {
			printf("%d\n", min_dist[i]);
		}
	}
	return 0;
}