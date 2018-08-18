#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
	데우는데 걸리는 시간은 어차피 같으니까
	먹는데 오래걸리는거부터 데워야 총 시간이 짧아진다.
*/

int n, e[10001], m[10001];
int heat() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; i++) {
		order.push_back(make_pair(-e[i], i));
	}
	sort(order.begin(), order.end());
	//먹는데 오래걸리는거부터 데워먹는 시간을 simulation.
	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; i++) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}
int main()
{	
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &m[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &e[i]);
		}		
		printf("%d\n", heat());
	}
	return 0;
}