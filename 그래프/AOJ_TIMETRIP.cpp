#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <float.h>

using namespace std;

vector<pair<int, int>> adj[101]; // <가중치,정점>

int N, M, V, E, st;
const int MAX_VALUE = 987654321;
bool reachable[101][101]; // i에서 j까지 가는 길이 존재하는가?

int bellmanFord(int st, int ed) {
	vector<int> upper(V, MAX_VALUE);
	upper[st] = 0;
	//V-1번 순회한다.
	for (int iter = 0; iter < V - 1; iter++) {
		for (int here = 0; here < V; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				// Relax
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
				}
			}
		}
	}
	//음수사이클
	for (int here = 0; here < V; here++) {
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			// Relax가 성공할 경우, 음수사이클이 존재
			// here,there 모두 음수사이클에 들어있다는 뜻
			if (upper[there] > upper[here] + cost) {
				if (reachable[st][here] && reachable[here][ed]) {
					return -MAX_VALUE;
				}
			}
		}
	}
	return upper[ed];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc-- > 0) {
		memset(reachable, false, sizeof(reachable));
		for (int i = 0; i < 101; i++) {
			adj[i].clear();
		}
		scanf("%d %d", &V, &E);
		int u, v, w;
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			reachable[u][v] = true;
		}
		//getReachable (floyd 알고리즘 응용)
		for (int k = 0; k < V; k++) {
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					if (reachable[i][k] && reachable[k][j]) {
						reachable[i][j] = true;
					}
				}
			}
		}
		//최단경로
		int minYear = bellmanFord(0, 1);
		//최장경로
		//가중치를 다 -로 변경
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				adj[i][j].second *= -1;
			}
		}
		int maxYear = bellmanFord(0, 1);
		if (!reachable[0][1]) {
			printf("UNREACHABLE\n");
		}
		else {
			if (minYear == MAX_VALUE || minYear == -MAX_VALUE) {
				printf("INFINITY ");
			}
			else {
				printf("%d ", minYear);
			}

			if (maxYear == MAX_VALUE || maxYear == -MAX_VALUE) {
				printf("INFINITY\n");
			}
			else {
				printf("%d\n", -maxYear);
			}
		}
	}
	return 0;
}