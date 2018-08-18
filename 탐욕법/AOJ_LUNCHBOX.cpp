#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
	����µ� �ɸ��� �ð��� ������ �����ϱ�
	�Դµ� �����ɸ��°ź��� ������ �� �ð��� ª������.
*/

int n, e[10001], m[10001];
int heat() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; i++) {
		order.push_back(make_pair(-e[i], i));
	}
	sort(order.begin(), order.end());
	//�Դµ� �����ɸ��°ź��� �����Դ� �ð��� simulation.
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