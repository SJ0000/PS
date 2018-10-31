#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int n, a, b;

void simulate() {
	int round = 0;
	int meet;
	int st, ed;
	while (true) {
		//라운드 시작.
		round++;
		meet = (1 << round) - 1;
		for (int i = 1; i <= n; i += meet + 1) {
			st = i; ed = i + meet;
			if (st <= a && a <= ed && st <= b && b <= ed) {
				printf("%d\n", round);
				return;
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &n, &a, &b);
	simulate();
	return 0;
}