#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int root[100001];
int n, m;
vector<pair<int, pair<int, int>>> edges;

int find(int x) {
	if (root[x] == x) {
		return x;
	}
	return root[x] = find(root[x]);
}


bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[a] = b;
	return true;
}

void init() {
	for (int i = 0; i < 100001; i++) {
		root[i] = i;
	}
}

long long kruskal() {

	long long mstCost = 0;
	int count = 0;
	int a, b, cost;
	for (int i = 0; i < m; i++) {
		pair<int, pair<int, int>> edge = edges[i];
		cost = edge.first;
		a = edge.second.first;
		b = edge.second.second;
		if (merge(a, b)) {
			mstCost += cost;
			count++;
		}
		if (count == n - 2) break;
	}

	return mstCost;
}

int main()
{
	scanf("%d %d", &n, &m);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(edges.begin(), edges.end());
	init();
	printf("%lld \n", kruskal());
	return 0;
}