#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int a[9][9] = { 0, };
bool row_check[9][10] = { false, };
bool col_check[9][10] = { false, };
bool sq_check[9][10] = { false, };


void dfs() {
	int x = -1, y = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] == 0) {
				x = i; y = j;
				break;
			}
		}
		if (x != -1) break;
	}

	if (x == -1) {
		//완성
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < 9; i++) {
			printf("%d ", a[8][i]);
		}
		exit(0);
	}

	//search
	for (int val = 1; val <= 9; val++) {
		//해당좌표의 row,col,sq 가 다 비어있을경우.
		if (!row_check[x][val] && !col_check[y][val] && !sq_check[(x / 3) * 3 + y][val]) {
			row_check[x][val] = col_check[y][val] = sq_check[(x / 3) * 3 + y][val] = true;
			a[x][y] = val;
			dfs();
			a[x][y] = 0;
			row_check[x][val] = col_check[y][val] = sq_check[(x / 3) * 3 + y][val] = false;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dfs();
	return 0;
}