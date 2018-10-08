#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, W, H;
int a[16][13];
int tmp[16][13];
int point[13]; // point[i]는 i번째 열의 가장 위 좌표
vector<int> block[13];
int minBlock;
int remainBlock;
//shoot -> update -> shoot -> update -> ....
//x,y에 공이 떨어졌을때. a[x][y]의 변화
void shoot(int x,int y) {
	if (!(0 <= x && x < H && 0 <= y && y < W)) {
		return;
	}
	if (tmp[x][y] == 0) return;
	int n = tmp[x][y] - 1;
	tmp[x][y] = 0;
	for (int i = 1; i <= n; i++) {
		shoot(x + i, y);
		shoot(x - i, y);
		shoot(x, y - i);
		shoot(x, y + i);
	}	
}
void update() {
	for (int i = 0; i < W; i++) {
		block[i].clear();
	}
	//블록 값을 아래에서 위로 저장.
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (tmp[j][i] > 0) block[i].push_back(tmp[j][i]);
			tmp[j][i] = 0;
		}
	}
	for (int i = 0; i < W; i++) {
		point[i] = H - block[i].size();
	}
	for (int i = 0; i < W; i++) {
		int bidx = 0;
		for (int j = H - 1; j >= point[i]; j--) {
			tmp[j][i] = block[i][bidx++];
		}
	}
}
void choice(vector<int> picked) {
	//0 ~ w-1 중에 중복가능 4개를 고르는 함수.
	if (picked.size() == N) {
		remainBlock = 0;
		//tmp에 a를 복사해서 picked에 선택된 위치에 공을 떨굼.
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				tmp[i][j] = a[i][j];
			}
		}
		// shoot 
		update();
		for (int i = 0; i < picked.size(); i++) {
			shoot(point[picked[i]], picked[i]);
			update();
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (tmp[i][j] > 0) remainBlock++;
			}
		}
		minBlock = min(minBlock, remainBlock);
		return;
	}
	for (int i = 0; i < W; i++) {
		picked.push_back(i);
		choice(picked);
		picked.pop_back();
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d %d %d", &N, &W, &H);
		minBlock = 987654321;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		vector<int> v;
		choice(v);
		printf("#%d %d\n", t_case, minBlock);
	}

	return 0;
}