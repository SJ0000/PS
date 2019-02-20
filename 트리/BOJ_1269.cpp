#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

int main()
{
	set<int> s;
	int n, m;
	scanf("%d %d", &n, &m);
	int intersection_n = 0;
	int val;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		s.insert(val);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &val);
		if (s.find(val) == s.end()) {
			s.insert(val);
		}
		else {
			intersection_n++;
		}
	}
	printf("%d\n", s.size() - intersection_n);
	return 0;
}