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
typedef pair<int, int> pii;
int n, m, k;
const int maxn = 100000;
pii seg[4 * maxn];
const long long maxval = 1000000001;
const long long minval = 0;

// pos : 리프노드 번호 , node : 트리의 노드 번호

pii update(int pos, pii val, int node, int x, int y) { // x~y 까지
	if (pos < x || y < pos) {
		return seg[node];
	}
	if (x == y) {
		return seg[node] = val;
	}
	int mid = (x + y) / 2;

	pii left = update(pos, val, node * 2, x, mid);
	pii right = update(pos, val, node * 2 + 1, mid + 1, y);
	return seg[node] = make_pair(min(left.first, right.first), max(left.second, right.second));
}

pii query(int lo, int hi, int node, int x, int y) {
	//x~y에서 벗어난 경우
	if (y < lo || hi < x) {
		return make_pair(maxval, minval); // 최소,최대 계산에 영향을 끼치지 않는 값.
	}
	// lo~hi가 x~y내부에 있는 경우
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) / 2;
	pii left = query(lo, hi, node * 2, x, mid);
	pii right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return make_pair(min(left.first, right.first), max(left.second, right.second));
}


int main()
{
	int t;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		update(i, make_pair(t, t), 1, 1, n);
	}
	pii ans;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		ans = query(a, b, 1, 1, n);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}