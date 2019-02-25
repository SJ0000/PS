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
int n, q;
const int maxn = 1000000;
ll seg[4 * maxn];

//index : 업데이트 하고자하는 번호, node : 현재 방문한 노드 번호
ll update(int index, int node, ll val, int st, int ed) {
	if (index < st || index > ed) {
		return 0;
	}
	if (st == ed) {
		seg[node] += val;
		return seg[node];
	}
	int mid = (st + ed) / 2;

	update(index, node * 2, val, st, mid);
	update(index, node * 2 + 1, val, mid + 1, ed);
	return seg[node] += val;
}

ll query(int x, int y, int node, int st, int ed) {
	//벗어나는 경우
	if (y < st || ed < x) {
		return 0;
	}
	//안에 들어온 경우
	if (x <= st && ed <= y) {
		return seg[node];
	}
	//나머지
	int mid = (st + ed) / 2;
	return query(x, y, node * 2, st, mid) + query(x, y, node * 2 + 1, mid + 1, ed);
}

int main()
{
	scanf("%d %d", &n, &q);
	int command, x, y;
	while (q--) {
		scanf("%d %d %d", &command, &x, &y);
		if (command == 1) {
			update(x, 1, (ll)y, 1, n);
		}
		else {
			printf("%lld\n", query(x, y, 1, 1, n));
		}
	}
	return 0;
}