#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

//단순하게 가로네줄 세로네줄 중에 최대값했을때 안풀림
// 1000
// 0001
// 0000
// 1000   - > 1000 + 1000 + 10 이 최대.
//dfs완전탐색.

using namespace std;

int N, M;
string s[4];

bool check[4][4] = { false, };
int block[] = { 0,1,2,3,10,20,30 };
int ans = -1;

void dfs(int before) {
	int tmp;
	int x = -1, y = -1;
	//선택 안 된 인덱스를 찾는다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) {
				x = i; y = j;
				break;
			}
		}
		if (x != -1) break;
	}
	//다고른경우.
	if (x == -1) {
		ans = max(ans, before);
		return;
	}
	bool full;
	//고르기
	for (int pos : block) {
		int bx = pos / 10;
		int by = pos % 10;
		full = false;
		//범위 체크
		if (0 <= x + bx && x + bx < N && 0 <= y + by && y + by < M) {
			//해당블록에 이미 자리가 차있으면 끼울 수 없음.
			for (int i = x; i <= x + bx; i++) {
				for (int j = y; j <= y + by; j++) {
					if (check[i][j]) {
						full = true;
						break;
					}
				}
				if (full) break;
			}
			if (full) continue;

			tmp = 0;
			for (int i = x; i <= x + bx; i++) {
				for (int j = y; j <= y + by; j++) {
					tmp += s[i][j] - '0';
					tmp *= 10;
					check[i][j] = true;
				}
			}
			dfs(before + tmp / 10);
			//백트래킹
			for (int i = x; i <= x + bx; i++) {
				for (int j = y; j <= y + by; j++) {
					check[i][j] = false;
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}