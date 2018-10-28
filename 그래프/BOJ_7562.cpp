#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int L;
int x, y, gox, goy;
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
bool check[301][301];

int bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	check[x][y] = true;
	int ret = 0;
	int nowx, nowy, ax, ay;
	while (!q.empty()) {
		int qs = q.size();
		for (int timer = 0; timer < qs; timer++) {
			pair<int, int> p = q.front(); q.pop();
			nowx = p.first; nowy = p.second;

			if (nowx == gox && nowy == goy) return ret;

			for (int i = 0; i < 8; i++) {
				ax = nowx + dx[i];
				ay = nowy + dy[i];
				if (0 <= ax && ax < L && 0 <= ay && ay < L) {
					if (!check[ax][ay]) {
						check[ax][ay] = true;
						q.push(make_pair(ax, ay));
					}
				}
			}
		}
		ret++;
	}
	return ret;
}


int main()
{
	int t;
	scanf("%d", &t);
	int x, y;
	while (t-- > 0) {

		scanf("%d", &L);
		scanf("%d %d", &x, &y);
		scanf("%d %d", &gox, &goy);
		memset(check, false, sizeof(check));
		printf("%d\n", bfs(x, y));

	}
	return 0;
}