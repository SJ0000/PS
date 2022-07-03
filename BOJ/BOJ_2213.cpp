#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>

using namespace std;


//SNS와 차이점 : 적게골라도 비싼걸 먹어야 한다.

const int maxn = 10001;
int dp[maxn][2]; // dp[i][0] == i의 부모가 independent set가 아닐때 최대값.
int n, w[maxn];
vector<int> tree[maxn], child[maxn];
bool check[maxn];
vector<int> route;
//graph -> tree;
void dfs(int now) {
	check[now] = true;	
	for (int next : tree[now]) {
		if (!check[next]) {
			child[now].push_back(next);
			dfs(next);
		}
	}
}
//부분문제.. 쪼개기..
int calc(int now, bool state) {

	int &ret = dp[now][state];
	if (ret != -1) return ret;
	
	ret = 0;	
	//내가 안골라진 경우.
	if (state == 0) {		
		for (int next : child[now]) {
			ret += max(calc(next, true),calc(next,false));
		}
	}
	else { //내가 골라진 경우 자식은 고를수 없음.
		ret = w[now];
		for (int next : child[now]) {
			ret += calc(next, false);
		}
	}
	return ret;
}
//추적 
void chase(int now, bool pi) {

	if (pi) {
		route.push_back(now);
		for (int next : child[now]) {
			chase(next, 0);
		}
	}
	else {
		for (int next : child[now]) {
			//더 큰거로 이동
			if (dp[next][1] >= dp[next][0]) {
				chase(next, 1);
			}
			else {
				chase(next, 0);
			}
		}
	}
}

int main()
{	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}	
	dfs(1);
	memset(dp, -1, sizeof(dp));
	
	int x = calc(1, 0);
	int y = calc(1, 1);

	if (x > y) {
		chase(1, 0);
	}
	else {
		chase(1, 1);
	}
	sort(route.begin(),route.end());
	printf("%d\n", max(x, y));
	for (int now : route) {
		printf("%d ", now);
	}

	return 0;
}