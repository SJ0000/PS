#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

vector<pair<int, int>> list;
int max_point;
void go(int n, int my_point, int remain) {
	//Base
	if (remain < 0) return;

	if (n == list.size()) {
		max_point = max(my_point, max_point);
		return;
	}
	int nowPoint = list[n].first;
	int nowKcal = list[n].second;
	//n번째 먹는경우
	go(n + 1, my_point + nowPoint, remain - nowKcal);
	//n번째 안먹는경우
	go(n + 1, my_point, remain);
}

int main()
{	
	int T;	
	cin >> T;
	int n, l, point, kcal;
	for (int t = 1; t <= T; t++) {
		list.clear();
		max_point = 0;
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &point, &kcal);
			list.push_back(make_pair(point, kcal));			
		}
		go(0, 0, l);
		printf("#%d %d\n", t, max_point);
	}
	return 0;
}