#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

//동서남북 1,2,3,4
int dx[5] = { 0, 0,0,1,-1 };
int dy[5] = { 0, 1,-1,0,0 };
int type[7][4] = { {1,2,3,4},{0,0,3,4},{1,2,0,0},{1,0,0,4},{1,0,3,0},{0,2,3,0},{0,2,0,4} };
int under[51][51];
bool check[51][51];
bool point[51][51];
int m, n, r, c, l;

vector<pair<int, int>> temp;
//update방식으로

bool hasRoute(pair<int,int> next,int go) {
	//x -> y 방향이 go 일때 갈수있는지 없는지.
	//go : 동서남북 1234
	int next_type = under[next.first][next.second]-1;
	//ex) 동쪽으로 갈때는 next에 서쪽이 뚫려있어야 한다.
	if (go == 0) {
		if (type[next_type][1]) return true;
	}
	if (go == 1) {
		if (type[next_type][0]) return true;
	}
	if (go == 2) {
		if (type[next_type][3]) return true;
	}
	if (go == 3) {
		if (type[next_type][2]) return true;
	}
	return false;
}
void update() {
	int now_type;
	int ax, ay;
	//갈 수 있는 장소를 임시 저장.
	temp.clear();
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (!point[x][y]) continue;
			now_type = under[x][y] -1;
			for (int i = 0; i < 4; i++) {
				ax = x + dx[type[now_type][i]];
				ay = y + dy[type[now_type][i]];
				if (0 <= ax && ax < n && 0 <= ay && ay < m) {
					//못 가는 곳 이나 이미 갈 수 있는 장소면 pass	
					if (check[ax][ay] || point[ax][ay]) {
						continue;
					}
					if (!hasRoute(make_pair(ax, ay), i)) {
						continue;
					}
					temp.push_back(make_pair(ax, ay));
				}
			}
		}
	}
	//업데이트
	for (pair<int, int> p : temp) {
		point[p.first][p.second] = true;
	}
}
int main(void) {
	int T;
	scanf("%d", &T);	
	int ans;
	for(int t_case = 1; t_case <= T; t_case++) {
		memset(check, false, sizeof(check));
		memset(point, false, sizeof(point));
		ans = 0;
		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &under[i][j]);
				if (under[i][j] == 0) {
					check[i][j] = true;
				}
			}
		}
		point[r][c] = true;
		for (int i = 1; i < l; i++) {
			update();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (point[i][j]) ans++;
			}
		}
		printf("#%d %d\n", t_case, ans);
	}
	return 0;
}