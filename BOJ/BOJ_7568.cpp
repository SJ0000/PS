#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

const int MAX = 10000000;
int ans[1000001];

int getAns(int val) {
	int ret = 0;
	int tmp = val;
	while (tmp > 10) {
		ret += tmp % 10;
		tmp /= 10;
	}
	ret += tmp;
	ret += val;
	return ret;
}
int main()
{		
	for (int i = 1; i <= 1000000; i++) {
		ans[i] = MAX;
	}
	int temp;
	for (int i = 1; i <= 1000000; i++) {
		temp = getAns(i);
		ans[temp] = min(ans[temp],i);
	}
	int input;
	scanf("%d", &input);
	if (ans[input] == MAX) {
		printf("%d\n", 0);
	}
	else {
		printf("%d\n", ans[input]);
	}
	return 0;
}