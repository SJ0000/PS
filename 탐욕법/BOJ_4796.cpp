#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
	int l, p, v;
	int ret;
	int _case = 1;
	while (true) {
		scanf("%d%d%d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;

		ret = 0;
		ret += (v / p)*l;
		if (v%p < l) ret += v % p;
		else ret += l;

		printf("Case %d: %d\n", _case++, ret);
	}

	return 0;
}