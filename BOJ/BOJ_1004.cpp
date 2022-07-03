#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int stx, sty, edx, edy;

bool isInCircle(int cx,int cy, int cr , int x ,int y) {
	int dist_sq = (cx - x)*(cx - x) + (cy - y)*(cy - y);
	int r_sq = cr * cr;
	if (dist_sq < r_sq) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{		
	int t;
	scanf("%d", &t);
	int n,ans;
	int x, y, r;
	bool in_st, in_ed;
	while (t-- > 0) {
		ans = 0;
		scanf("%d %d %d %d", &stx, &sty, &edx, &edy);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &r);
			in_st = isInCircle(x, y, r, stx, sty);
			in_ed = isInCircle(x, y, r, edx, edy);
			if ((in_st && in_ed) || (!in_st&&!in_ed)) {

			}
			else {
				ans++;
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}