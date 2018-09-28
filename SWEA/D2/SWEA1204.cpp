#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int a[101];

int getAns() {
	int ret = 0;
	int st = a[0];
	for (int i = 0; i <= 100; i++) {
		if (st <= a[i]) {
			st = a[i];
			ret = i;
		}
	}
	return ret;
}

int main()
{	
	int T;
	cin >> T;
	int n, val;
	for (int t = 1; t <= T; t++) {
		memset(a, 0, sizeof(a));
		cin >> val;
		for (int i = 0; i < 1000; i++) {
			scanf("%d", &val);
			a[val]++;
		}
		printf("#%d %d\n", t, getAns());
	}
	return 0;
}