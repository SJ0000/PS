#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

vector<int> g[501];
bool check1[501];
bool check2[501];

//dfs로 정점의 개수와 간선의 개수를 구한다.
int dfs1(int idx) {
	int v = 1;
	check1[idx] = true;
	for (int next : g[idx]) {
		if (!check1[next]) {
			v += dfs1(next);
		}
	}
	return v;
}

int dfs2(int idx) {
	int e = g[idx].size();
	check2[idx] = true;
	for (int next : g[idx]) {
		if (!check2[next]) {
			e += dfs2(next);
		}
	}
	return e;
}



void init() {	
	for (int i = 0; i < 501; i++) {
		g[i].clear();
		check1[i] = false;
		check2[i] = false;
	}
}

void printAns(int case_, int ans) {
	if (ans == 0) {
		printf("Case %d: No trees.\n", case_);
	}
	else if (ans == 1) {
		printf("Case %d: There is one tree.\n", case_);
	}
	else {
		printf("Case %d: A forest of %d trees.\n", case_, ans);
	}
}

int main()
{	
	int n, m, a, b;
	int case_ = 0;
	int ans;

	while (true) {
		scanf("%d %d", &n, &m);
		init();
		case_++;
		ans = 0;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 0; i < n; i++) {
			if (!check1[i]) {
				int v = dfs1(i);
				int e = dfs2(i);
				if (v - 1 == e / 2) ans++;
			}
		}	
		printAns(case_,ans);
	}
	return 0;
}