#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int R, C;
char a[51][51];
bool wcheck[51][51];
bool bcheck[51][51];
bool dfschecker[51][51];
queue<pair<int, int>> beaver;
queue<pair<int, int>> water;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int edx, edy;
bool hasRoute;

void dfs(int x, int y) {
	if (hasRoute) return;
	if (a[x][y] == 'S') {
		hasRoute = true;
		return;
	}
	if (dfschecker[x][y]) return;
	dfschecker[x][y] = true;

	int ax, ay;
	for (int i = 0; i < 4; i++) {
		ax = x + dx[i]; ay = y + dy[i];
		if (0 <= ax && ax < R && 0 <= ay && ay < C) {
			if (a[ax][ay] == '.' || a[ax][ay] == 'S') {
				dfs(ax, ay);
			}
		}
	}
}
int getAns() {
	int timer = 1;
	int x, y, ax, ay;
	int qs;
	memset(wcheck, false, sizeof(wcheck));
	memset(bcheck, false, sizeof(bcheck));
	while (true) {
		//test
		/*
		printf("TIME : %d \n", timer);
		for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
		cout << a[i][j] << " ";
		}
		cout << endl;
		}
		*/
		qs = water.size();
		for (int ii = 0; ii < qs; ii++) {
			x = water.front().first;
			y = water.front().second;
			water.pop();

			if (wcheck[x][y]) continue;
			wcheck[x][y] = true;

			for (int i = 0; i < 4; i++) {
				ax = x + dx[i]; ay = y + dy[i];
				if (0 <= ax && ax < R && 0 <= ay && ay < C) {
					if (a[ax][ay] == 'X' || a[ax][ay] == 'D') continue;
					water.push(make_pair(ax, ay));
					a[ax][ay] = '*';
				}
			}
		}
		//비버
		qs = beaver.size();
		for (int ii = 0; ii < qs; ii++) {
			x = beaver.front().first;
			y = beaver.front().second;
			beaver.pop();

			if (bcheck[x][y]) continue;
			bcheck[x][y] = true;

			for (int i = 0; i < 4; i++) {
				ax = x + dx[i]; ay = y + dy[i];
				//빈칸이거나 굴일때만 갈 수 있다.
				if (0 <= ax && ax < R && 0 <= ay && ay < C) {
					if (a[ax][ay] == '.' || a[ax][ay] == 'D') {
						beaver.push(make_pair(ax, ay));
						a[ax][ay] = 'S';
					}
				}
			}
		}
		//비버가 도착한 경우.
		if (a[edx][edy] == 'S') return timer;
		//비버가 못오는 경우. 
		//dfs해서 B가 S랑 못만나는경우.
		hasRoute = false;
		memset(dfschecker, false, sizeof(dfschecker));
		dfs(edx, edy);
		if (!hasRoute) return -1;

		timer++;
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	string s;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'D') {
				edx = i; edy = j;
			}
			else if (a[i][j] == '*') {
				water.push(make_pair(i, j));
			}
			else if (a[i][j] == 'S') {
				beaver.push(make_pair(i, j));
			}
		}
	}
	int ans = getAns();
	if (ans == -1) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}