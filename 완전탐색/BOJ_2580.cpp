#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>

using namespace std;

int a[9][9];
vector<int> zero;

//a[x][y]에 input이 들어갈 수 있으면 true
bool check(int x, int y, int input) {
	//가로,세로
	for (int i = 0; i < 9; i++) {
		if (a[x][i] == input || a[i][y] == input) return false;
	}
	//사각형
	int sqx = (x / 3) * 3;
	int sqy = (y / 3) * 3;
	for (int i = sqx; i < sqx + 3; i++) {
		for (int j = sqy; j < sqy + 3; j++) {
			if (a[i][j] == input) return false;
		}
	}
	return true;
}

void solve(int idx) {

	if (zero.size() == idx) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	int	nowx = zero[idx] / 10;
	int	nowy = zero[idx] % 10;

	//가로,세로,사각형 검사해서 넣을수있으면 넣고 백트래킹
	for (int input = 1; input <= 9; input++) {
		if (check(nowx, nowy, input)) {
			a[nowx][nowy] = input;
			solve(idx + 1);
			a[nowx][nowy] = 0;
		}
	}
	return;
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) {
				zero.push_back(i * 10 + j);
			}
		}
	}
	solve(0);
	return 0;
}