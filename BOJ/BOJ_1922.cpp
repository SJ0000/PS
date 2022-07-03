#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>


using namespace std;
vector <pair<int, int>> g[1001];
int V, E;

struct unionFind {
	vector<int> parent, rank;
	unionFind(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			//자기의 부모는 자기자신
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return; // 이미 합쳐진 상태
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;

	}
};

int kruskal() {
	int ret = 0;
	unionFind uf(V);

	vector<pair<int, pair<int, int>> > edges;
	vector<pair<int, int>> selected;
	for (int u = 0; u < V; u++) {
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first, cost = g[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		//간선 u,v를 검사.
		int cost = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		//이미 연결된 상태일경우 무시.
		if (uf.find(u) == uf.find(v)) continue;

		uf.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}

int main()
{
	scanf("%d %d", &V, &E);
	int u, v, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	cout << kruskal() << endl;
	return 0;
}