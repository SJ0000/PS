#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

const int sz = 1001;
bool pipe[sz];

int getAns(int l) {
	int ret = 0;
	for (int i = 0; i < sz; i++) {
		//i에서 물이새면 i부터 l만큼 테이핑
		if (pipe[i]) {
			for (int taping = 0; taping < l; taping++) {
				pipe[i + taping] = false;
			}
			ret++;
		}
	}
	return ret;
}


int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	int pos;
	memset(pipe, false, sizeof(pipe));
	while (n-- > 0) {
		scanf("%d", &pos);
		pipe[pos] = true;
	}

	printf("%d\n", getAns(l));
	return 0;
}