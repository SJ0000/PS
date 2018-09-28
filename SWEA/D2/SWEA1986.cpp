#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;


int main()
{	
	int T;
	cin >> T;
	int a[11];
	a[0] = 0;
	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 1) {
			a[i] = a[i - 1] + i;
		}
		else {
			a[i] = a[i - 1] - i;
		}
	}
	int n;
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		printf("#%d %d\n", t, a[n]);
	}
	return 0;
}