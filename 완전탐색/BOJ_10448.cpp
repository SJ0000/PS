#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int N;
vector<int> tnum; // triangle num;

void precalc() {
	for (int i = 1; i*(i + 1) / 2 <= 1000; i++) {
		tnum.push_back((i*(i + 1)) / 2);
	}
}
void calc(int num) {
	int sz = tnum.size();
	bool getans = false;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				if ((tnum[i] + tnum[j] + tnum[k]) == num) {
					getans = true;
					break;
				}
			}
			if (getans) break;
		}
		if (getans) break;
	}
	getans ? printf("1\n") : printf("0\n");
}
int main()
{
	precalc();
	int tc; scanf("%d", &tc);
	int val;
	while (tc-- > 0) {
		scanf("%d", &val);
		calc(val);
	}
	return 0;
}