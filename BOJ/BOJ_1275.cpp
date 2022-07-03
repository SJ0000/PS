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
typedef long long ll;
const int maxn = 100001;
int n, q;

ll seg[4 * maxn];

ll update(int index, int node, ll val, int st, int ed) {
	if (index < st || ed < index) {
		return 0;
	}
	if (st == ed) {
		return seg[node] += val;
	}
	int mid = (st + ed) / 2;
	//여기서 더하고 가야하는듯.
	update(index, node * 2, val, st, mid);
	update(index, node * 2 + 1, val, mid + 1, ed);
	return seg[node] += val;
}

//구하고자하는거 x~y 구간합

ll query(int x, int y, int node, int st, int ed) {
	if (y < st || ed < x) {
		return 0;
	}
	if (x <= st && ed <= y) {
		return seg[node];
	}
	int mid = (st + ed) / 2;
	return query(x, y, node * 2, st, mid) + query(x, y, node * 2 + 1, mid + 1, ed);
}

int main()
{
	scanf("%d %d", &n, &q);
	ll val;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &val);
		update(i, 1, val, 1, n);
	}
	int x, y, a; ll b, diff;
	while (q--) {
		scanf("%d %d %d %lld", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", query(x, y, 1, 1, n));
		diff = b - query(a, a, 1, 1, n);
		update(a, 1, diff, 1, n);
	}
	return 0;
}