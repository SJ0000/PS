#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<pair<int, int>> p;

int n;
void calc() {
	int point = 0;
	int plan[1001] = { 0, };

	for (int i = 0; i < n; i++) {
		int now = p[i].second;
		for (int j = now; j >= 1; j--) {
			if (plan[j] == 0) {
				plan[j] = p[i].first;
				break;
			}
		}
	}
	for (int i = 0; i < 1001; i++) {
		point += plan[i];
	}
	printf("%d\n", point);
}
bool desc(pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}

int main()
{
	scanf("%d", &n);
	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		p.push_back(make_pair(y, x));
	}
	sort(p.begin(), p.end(), desc);
	calc();
	return 0;
}