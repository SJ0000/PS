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

int m, n;
const int MAXN = 200001;
int uf[MAXN];
typedef pair<int, pair<int, int>> pipii;
int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

int main()
{
	while (true) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;
		int x, y, z;
		vector<pipii> v;
		int totalCost = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			v.push_back(make_pair(z, make_pair(x, y)));
			totalCost += z;
		}
		fill_n(uf, MAXN, -1);
		int mstCost = 0;
		int edgeCount = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			pipii now = v[i];
			pair<int, int> uv = now.second;
			//합쳐졌으면, 즉 다른 집합이었던 경우-> 추가.
			if (merge(uv.first, uv.second)) {
				//				printf("%d %d -> %d union \n", uv.first, uv.second, now.first);
				mstCost += now.first;
				edgeCount++;
			}
			if (edgeCount == m - 1) break;
		}
		printf("%d\n", totalCost - mstCost);
	}



	return 0;
}