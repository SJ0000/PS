#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//이익이 0밑으로 떨어지지 않으면서 최대한 많은 집을 커버하게

vector<pair<int, int>> area[22];
int a[21][21];
int N, M;
int max_home,total_home;
void setArea() {
	area[1].push_back(make_pair(0, 0));
	int stx, sty;
	int nowx, nowy;
	for (int i = 2; i <= 21 ; i++) {
		area[i].assign(area[i - 1].begin(), area[i - 1].end());
		stx = -1 * (i-1);
		sty = 0;
		nowx = stx; nowy = sty;
		// 1
		while (!(nowx == 0 && nowy == stx)) {
			area[i].push_back(make_pair(nowx, nowy));
			nowx++; nowy--;
		}
		// 2
		while (!(nowx == -1*stx && nowy == 0)) {
			area[i].push_back(make_pair(nowx, nowy));
			nowx++; nowy++;
		}
		while (!(nowx == 0 && nowy == -1*stx)) {
			area[i].push_back(make_pair(nowx, nowy));
			nowx--; nowy++;
		}
		while (!(nowx == stx && nowy == sty)) {
			area[i].push_back(make_pair(nowx, nowy));
			nowx--; nowy--;
		}
	}
}
void search(int stx, int sty) {
	for (int i = 1; i <= 21; i++) {
		int money = (i * i) + ((i - 1)*(i - 1));
		int home = 0;
		for (pair<int, int> pos : area[i]) {
			int ax = stx + pos.first;
			int ay = sty + pos.second;
			if (0 <= ax && ax < N && 0 <= ay && ay < N) {
				if (a[ax][ay] == 1) home++;
			}
		}	
		if ((home*M) - money >= 0) {
			max_home = max(home, max_home);
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	setArea();
	bool allCovered;
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d %d", &N, &M);
		max_home = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 1) total_home++;
			}				
		}
		//최대 이익을 찾는 것이 아니니 area가 1~10까지 다해본다.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {				
				search(i, j);
			}
		}
		printf("#%d %d\n", t_case, max_home);
	}
	return 0;
}