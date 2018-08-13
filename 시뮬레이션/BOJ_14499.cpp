#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int map[20][20];
int dice[7] = {0,0,0,0,0,0,0 };
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int b, r;

int main() {	
	int n, m, x, y, k;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		int go;
		scanf("%d", &go);
		int nx = x + dx[go];
		int ny = y + dy[go];
		if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) {
			continue;
		}
		int ndice[7] = { 0, };
		if (go == 1) {
			ndice[3] = dice[1];
			ndice[1] = dice[4];
			ndice[4] = dice[6];
			ndice[6] = dice[3];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		if (go == 2) {
			ndice[1] = dice[3];
			ndice[3] = dice[6];
			ndice[6] = dice[4];
			ndice[4] = dice[1];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		if (go == 3) {
			ndice[1] = dice[5];
			ndice[5] = dice[6];
			ndice[6] = dice[2];
			ndice[2] = dice[1];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
		}
		if (go == 4) {
			ndice[1] = dice[2];
			ndice[2] = dice[6];
			ndice[6] = dice[5];
			ndice[5] = dice[1];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
		}
		//ĭ�� ���ִ°� 0�̸� �ֻ����ٴ��� ĭ���� ����;
		if (map[nx][ny] == 0) {
			map[nx][ny] = ndice[6];
		}
		else {
			//0�� �ƴϸ� ĭ���ִ� ���� �ֻ����� �����ϰ� ĭ�� ���� 0����
			ndice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		printf("%d\n", ndice[1]);
		for (int i = 0; i < 7; i++) {
			dice[i] = ndice[i];
		}
		x = nx;
		y = ny;
	}
	return 0;
}