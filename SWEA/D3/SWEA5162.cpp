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
	int a, b, c;

	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &a, &b, &c);
		a = min(a, b);
		printf("#%d %d\n", t, c / a);
	}
	return 0;
}