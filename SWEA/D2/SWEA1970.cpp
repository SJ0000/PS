#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int a[8];

void search(int m) {
	memset(a, 0, sizeof(a));
	int k = 50000;
	for (int i = 0; i < 8; i++) {
		a[i] = m / k;
		m %= k;
		if (i % 2 == 0) {
			k /= 5;
		}
		else {
			k /= 2;
		}
	}
}
int main()
{	
	int T;
	cin >> T;
	int money;
	for (int t = 1; t <= T; t++) {
		scanf("%d", &money);
		search(money);

		printf("#%d\n",t);
		for (int i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}