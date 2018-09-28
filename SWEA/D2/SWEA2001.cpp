#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;
int area[16][16];
int n, m;


int atk() {
	int ret = 0;
	int tmp;
	for (int stx = 0; stx <= n - m; stx++) {
		for (int sty = 0; sty <= n - m; sty++) {
			tmp = 0;
			for (int i = stx; i < stx + m; i++) {
				for (int j = sty; j < sty + m; j++) {
					tmp += area[i][j];
				}
			}
			ret = max(ret, tmp);
		}
	}
	return ret;
}

int main()
{	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &area[i][j]);
			}
		}
		int ans = atk();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}