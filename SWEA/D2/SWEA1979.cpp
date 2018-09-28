#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int a[16][16];
int n, k;

int search() {
	int ret = 0;
	int cnt;
	//가로검사
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				cnt++;
			}
			else {
				if (cnt == k) {
					ret++;
				}
				cnt = 0;
			}
		}
		if (cnt == k) {
			ret++;
		}
	}
	//세로검사
	for (int j = 0; j < n; j++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 1) {
				cnt++;
			}
			else {
				if (cnt == k) {
					ret++;	
				}
				cnt = 0;
			}
		}
		if (cnt == k) {
			ret++;
		}
	}
	return ret;
}


int main()
{	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("#%d %d\n", t, search());
	}
	return 0;
}