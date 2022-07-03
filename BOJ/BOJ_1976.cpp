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

int parent[201];

//union-find

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int connect;
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &connect);
			if (connect == 1) {
				merge(i, j);
			}
		}
	}
	int st, go;
	scanf("%d", &st);
	bool isPossible = true;
	for (int i = 0; i < m - 1; i++) {
		scanf("%d", &go);
		if (find(st) != find(go)) {
			isPossible = false;
			break;
		}
	}
	if (isPossible) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}