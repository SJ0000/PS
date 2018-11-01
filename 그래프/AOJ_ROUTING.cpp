#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <float.h>

using namespace std;

vector<pair<double, int>> g[20001]; // <����ġ,����>

int V, E, st;
double min_dist[10001];
bool check[10001];

//priority_queue�� ������������ �����ϱ⶧���� 
// dijkstra�˰��򿡼� ���� ���� ���� ������ ���� ����ġ�� -�� ������.

const double MAX_VALUE = DBL_MAX;

void dijkstra() {
	priority_queue<pair<double, int>> pq;
	min_dist[st] = 1;
	int nowv, nextv;
	double noww, nextw;
	double nextDist;
	pq.push(make_pair(-1, st));
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
			// nextDist : st~nextv������ ���� -> st~nowv ������ ���̰� noww, nowv~nextv ������ ���̰� nextw
			nextDist = noww * nextw;
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
	int tc = 0;
	scanf("%d", &tc);
	while (tc-- > 0) {
		scanf("%d %d", &V, &E);
		st = 0;
		int u, v;
		double w;
		for (int i = 0; i < V; i++) {
			min_dist[i] = MAX_VALUE;
			g[i].clear();
			check[i] = false;
		}
		for (int i = 0; i < E; i++) {
			scanf("%d %d %lf", &u, &v, &w);
			g[u].push_back(make_pair(w, v));
			g[v].push_back(make_pair(w, u));
		}
		dijkstra();

		cout << fixed;
		cout.precision(10);
		cout << min_dist[V - 1] << endl;

	}
	return 0;
}