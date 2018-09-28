#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

bool stu[101];
int n, k;
int main()
{	
	int T;	
	cin >> T;
	int val;
	for (int t = 1; t <= T; t++) {
		memset(stu, false, sizeof(stu));
		scanf("%d %d", &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &val);
			stu[val] = true;
		}
		printf("#%d ", t);
		for (int i = 1; i <= n; i++) {
			if (!stu[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}