#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;


bool nums[10][10][10];

void calc(int num, int strike, int ball) {
	int sz = 10;

	int x = num / 100;
	int y = (num - x * 100) / 10;
	int z = num % 10;

	int now_strike, now_ball;
	//a,b,c와  모든 수 x,y,z 를 비교
	for (int a = 0; a < sz; a++) {
		for (int b = 0; b < sz; b++) {
			for (int c = 0; c < sz; c++) {

				if (!nums[a][b][c]) continue;

				now_strike = now_ball = 0;

				//strike,ball 판별
				if (a == x) now_strike++;
				if (b == y) now_strike++;
				if (c == z) now_strike++;
				if (a == y || a == z) now_ball++;
				if (b == x || b == z) now_ball++;
				if (c == x || c == y) now_ball++;

				//판별 결과 조건에 맞지않으면 false;
				if (!(ball == now_ball && strike == now_strike)) {
					nums[a][b][c] = false;
				}

			}
		}
	}

}

void init() {
	int sz = 10;
	for (int a = 0; a < sz; a++) {
		for (int b = 0; b < sz; b++) {
			for (int c = 0; c < sz; c++) {
				//1~9까지니까 0은 존재하지않음
				if (a == 0 || b == 0 || c == 0) {
					nums[a][b][c] = false;
				}
				//서로다른 세 수
				if (a == b || b == c || c == a) {
					nums[a][b][c] = false;
				}
			}
		}
	}
}

int getAns() {
	int ret = 0;
	int sz = 10;
	for (int a = 0; a < sz; a++) {
		for (int b = 0; b < sz; b++) {
			for (int c = 0; c < sz; c++) {
				if (nums[a][b][c]) ret++;
			}
		}
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	memset(nums, true, sizeof(nums));
	init();
	int n, s, b;

	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &n, &s, &b);
		calc(n, s, b);
	}

	printf("%d\n", getAns());

	return 0;
}