#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N,max_pick;
int a[21][21];
bool dessert[101];
//0,1,2,3 ������� ������.
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
//������ ���ϴ� ���ϴ� ���� �»�� ���� ������.
//shape�� <int,int>��  ���ϴ�,����/���ϴ�,�»��  ���� Ƚ���� ����.
//������ �� ���� N�϶� shape�� �ּ� 1���� �ִ� N-2���� ����.
bool rangeCheck(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N) {
		return true;
	}
	else {
		return false;
	}
}
void go(int stx,int sty, int l, int r ) {
	
	//��ΰ� �ִٰ� �ĵ� ������ ����� �ִ밪���� ���� ���
	//���ϴ� �ǹ̰� ����.
	if (max_pick > (l * 2 + r * 2)) {
		return;
	}
	memset(dessert, false, sizeof(dessert));
	int x = stx; int y = sty;
	dessert[a[x][y]] = true;
	for (int i = 0; i < l; i++) {
		x += dx[0]; y += dy[0];
		if (!rangeCheck(x, y)) return;
		if (dessert[a[x][y]]) {
			return;
		}
		dessert[a[x][y]] = true;
	}
	for (int i = 0; i < r; i++) {
		x += dx[1]; y += dy[1];
		if (!rangeCheck(x, y)) return;
		if (dessert[a[x][y]]) {
			return;
		}
		dessert[a[x][y]] = true;
	}
	for (int i = 0; i < l; i++) {
		x += dx[2]; y += dy[2];
		if (!rangeCheck(x, y)) return;
		if (dessert[a[x][y]]) {
			return;
		}
		dessert[a[x][y]] = true;
	}
	//start�� ���ƿ��� ���� ���� ���ƾ� �Ѵ�.
	for (int i = 0; i < r-1; i++) {
		x += dx[3]; y += dy[3];
		if (!rangeCheck(x, y)) return;
		if (dessert[a[x][y]]) {
			return;
		}
		dessert[a[x][y]] = true;
	}	
	max_pick = max((2 * l + 2 * r), max_pick);
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d", &N);
		max_pick = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {				
				for (int l = 1; l <= N - 2; l++) {
					for (int r = 1; r <= N - 2; r++) {
						go(i, j, l, r);
					}
				}
			}
		}
		printf("#%d %d\n", t_case, max_pick);
	}
	return 0;
}