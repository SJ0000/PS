#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int h, m;
int main()
{	
	int T;
	cin >> T;
	int h1, m1, h2, m2;
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
		h = (h1 + h2 + (m1 + m2) / 60)%12;
		m = (m1 + m2) % 60;
		if (h == 0) {
			h = 12;
		}
		printf("#%d %d %d\n", t, h, m);
	}
	return 0;
}