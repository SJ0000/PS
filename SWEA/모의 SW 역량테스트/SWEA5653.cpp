#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

//x시간동안 비활성화 , 활성화 후 x 시간동안 생존.
//문제를 잘 읽자.

struct cell {
	int life;
	int x;
	int y;
};

int N, M, K;
int a[700][700];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<cell> q[11];

int calc() {
	int ax, ay;
	int ret = 0;
	for (int timer = 0; timer <= K; timer++) {	
		for (int life = 10; life >= 1; life--) {
			int qs = q[life].size();
			for (int i = 0; i < qs; i++) {
				cell cl = q[life].front(); q[life].pop();		
				if (cl.life > life) {
					if (a[cl.x][cl.y] > 0) {
						a[cl.x][cl.y] *= -1; ret++;
					}
					q[life].push(cell{ cl.life - 1,cl.x,cl.y });
				}
				else if (cl.life == life) {
					q[life].push({ cl.life - 1,cl.x,cl.y });
					for (int j = 0; j < 4; j++) {
						ax = cl.x + dx[j];
						ay = cl.y + dy[j];
						if (a[ax][ay]) continue;
						q[life].push(cell{ 2 * life,ax,ay });
						a[ax][ay] = life;
					}
				}
				else if (life > cl.life && cl.life) {
					q[life].push(cell{ cl.life - 1,cl.x,cl.y });
				}
				else {
					ret--;
				}
			}
		}
	}
	return ret;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d %d %d", &N, &M, &K);
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= 10; i++) {
			while (!q[i].empty()) {
				q[i].pop();
			}
		}		
		for (int i = 300; i < 300 + N; i++) {
			for (int j = 300; j < 300 + M; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j]) {
					q[a[i][j]].push(cell{ 2 * a[i][j],i,j });
				}
			}
		}
		printf("#%d %d\n", t_case, calc());
	}
	return 0;
}