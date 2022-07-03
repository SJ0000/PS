#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;
vector<int> v;
int m, n;
void dfs() {	
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}
}

int main()
{		
	scanf("%d %d", &n, &m);
	dfs();
	return 0;
}