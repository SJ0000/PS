#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
//dir = 0 1 2 3 : u,d,l,r;


int a[102][102];
int b[6][4] = { {0,0,0,0},{1,3,0,2},{3,0,1,2} ,{2,0,3,1},{1,2,3,0},{1,0,3,2} }; //b[i][j] : i�� ��Ϲ�ȣ j�� ������ udlr �϶� ��Թٲ����.
int N,ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0 ,0,-1,1 };
//wormhole�� 6 7 8 9 10 �� ���ⱸ ��ǥ ����.
vector<int> wormhole[11];
vector<int> sp; // startPoint 

//���̳� ��� ������ +1�� (��Ȧ�� �������Ծȵ�.)
int simulate(int stx, int sty, int dir) {
	int mypoint = 0;
	int nowx = stx, nowy = sty, ndir = dir;
	int nval; // now_value

	//test
	//printf("*** SIMULATE START ***\n");
//	printf("stx : %d , sty : %d , dir : %d \n", stx, sty, dir);
	//tested

	do {
		//������ġ.
		nowx += dx[ndir];
		nowy += dy[ndir];
		//������̸� ����.
		nval = a[nowx][nowy];

	//	printf("nowx : %d , nowy : %d , ndir : %d \n", nowx, nowy, ndir);

		if (nval == 0) {
			continue;
		}else if (1 <= nval && nval <= 5) {
			//���� ���� ���.
			//�����԰� ���⺯��.
			mypoint++;
			ndir = b[nval][ndir];
			continue;
		}
		else if(6 <= nval && nval <= 10){
			//��Ȧ�� ���� ���.

	//		printf("WARP!!!!\n");
			for (int warp : wormhole[nval]) {
				if (nowx * 1000 + nowy != warp) {
					nowx = warp / 1000;
					nowy = warp % 1000;
					break;
				}
			}
		}
	} while (a[nowx][nowy] != -1 && !(nowx == stx && nowy == sty));

//	printf("point : %d\n", mypoint);
	return mypoint;
}
void init() {
	//�Է¹޴������� 1,1�̱⶧���� �迭�� 5�� �ʱ�ȭ �س�����
	//���� ����� ���� ó�� �� �ʿ䰡 ����.	
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			a[i][j] = 5;
		}
	}
	for (int i = 0; i < 11; i++) {
		wormhole[i].clear();
	}
	sp.clear();	
	ans = -1;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d", &N);
		init();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {				
				scanf("%d", &a[i][j]);
				if (a[i][j] == 0) {
					sp.push_back(i * 1000 + j);
				}
				else if (a[i][j] >= 6) {
					wormhole[a[i][j]].push_back(i * 1000 + j);
				}
			}
		}
		int stx, sty;
		for (int st : sp) {
			stx = st / 1000; sty = st % 1000;
			for (int i = 0; i < 4; i++) {
				ans = max(ans,simulate(stx, sty, i));
			}
		}
		printf("#%d %d\n", t_case, ans);
	}	
	return 0;
}