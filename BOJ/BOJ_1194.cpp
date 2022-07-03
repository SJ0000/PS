#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, stx, sty, edx, edy;
char maze[51][51];
bool check[51][51][1 << 6];

//BOJ_1194 달이차오른다
//열쇠를 비트마스크로 abcdef

void bfs() {

	queue<pair<int, int>> q;
	q.push(make_pair(stx * 100 + sty, 0)); // second의 0은 열쇠를 하나도 못먹은 상태라는 뜻이다.
	check[stx][sty][0] = true;
	int timer = -1;
	int nx, ny, nowKey;
	int ax, ay, doorKey;
	pair<int, int> now;
	while (!q.empty()) {
		int sz = q.size();
		//1타임
		timer++;
		//	printf("TIME : %d\n", timer);
		while (sz-- > 0) {
			now = q.front();
			q.pop();
			nx = now.first / 100;
			ny = now.first % 100;
			nowKey = now.second;
			//		printf("%d %d %d \n", nx, ny, nowKey);
			if (maze[nx][ny] == '1') {
				printf("%d", timer);
				exit(0);
			}
			for (int i = 0; i < 4; i++) {
				ax = nx + dx[i];
				ay = ny + dy[i];
				doorKey = 0;
				if (0 <= ax && ax < n && 0 <= ay && ay < m) {
					if (!check[ax][ay][nowKey]) {
						if ('a' <= maze[ax][ay] && maze[ax][ay] <= 'f') {	//열쇠 획득
							q.push(make_pair(ax * 100 + ay, nowKey | (1 << (maze[ax][ay] - 'a'))));
							check[ax][ay][nowKey | (1 << (maze[ax][ay] - 'a'))] = true;
						}
						else if ('A' <= maze[ax][ay] && maze[ax][ay] <= 'F') { // 문
							//열쇠가 있어야함		
							doorKey = (1 << (maze[ax][ay] - 'A'));
							// printf("DOOR phase : %d %d , key : %d %d \n", ax, ay, doorKey, (nowKey & doorKey));
							if ((nowKey & doorKey) == doorKey) {
								q.push(make_pair(ax * 100 + ay, nowKey));
								check[ax][ay][nowKey] = true;
							}
						}
						else if (maze[ax][ay] == '#') {

						}
						else {
							q.push(make_pair(ax * 100 + ay, nowKey));
							check[ax][ay][nowKey] = true;
						}
					}
				}
			}
		}
	}
	//큐가 빈 경우, 탈출못함
	printf("-1");
	return;
}


int main()
{
	scanf("%d %d", &n, &m);
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			maze[i][j] = str[j];
			if (maze[i][j] == '0') {
				stx = i;
				sty = j;
			}
			if (maze[i][j] == '1') {
				edx = i;
				edy = j;
			}
		}
	}
	bfs();
	return 0;
}