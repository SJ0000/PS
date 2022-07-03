#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;


// k-1∞≥ ªË¡¶.
int n, k;
vector<int> p;

void calc() {
	vector<int> d;
	for (int i = 0; i < n - 1; i++) {
		int val = p[i + 1] - p[i];
		d.push_back(p[i + 1] - p[i]);
	}
	sort(d.begin(), d.end());
	long long ret = 0;
	for (int i = 0; i < n - k; i++) {
		ret += d[i];
	}
	printf("%lld\n", ret);
}

int main()
{
	scanf("%d%d", &n, &k);
	int val;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		p.push_back(val);
	}
	sort(p.begin(), p.end());
	calc();
	return 0;
}