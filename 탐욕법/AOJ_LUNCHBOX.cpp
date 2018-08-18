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
		/*  max연산을 사용하는 이유
		     : i-1번째 음식을 데우는시간이 5초이고 먹는 시간이 5초일때 
		       i번째 음식을 데우는데 걸리는 시간이 2초이고 먹는시간이 2초이면
		       i번째 음식을 다 먹어도 9초이지만, 그 때 i-1번째 음식은 아직 먹는중이라서 
		       ret = max(ret(i-1번째 음식을 다 먹는 시간),beginEat+e[box](i번째 음식을 먹는데 걸리는 시간))
		       이다.
		*/
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
