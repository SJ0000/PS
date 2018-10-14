#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int m, n;
vector<int> g[2001]; // graph
bool check[2001];
int maxdeep;
void dfs(int now, int nowdeep) {

	if (maxdeep >= 5) return;
	maxdeep = max(maxdeep, nowdeep);

	check[now] = true;
	for (int next : g[now]) {
		if (!check[next]) {
			dfs(next, nowdeep + 1);
		}
	}
	check[now] = false;
}
int main()
{
	scanf("%d %d", &n, &m);
	int a, b;
	maxdeep = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(check, false, sizeof(check));
		dfs(i, 1);
	}
	if (maxdeep >= 5) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}