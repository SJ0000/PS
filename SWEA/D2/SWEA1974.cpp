#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

int a[9][9];
double ch[10];

int search() {
	int num;
	//가로검사
	for (int i = 0; i < 9; i++) {
		memset(ch, false, sizeof(ch));
		for (int j = 0; j < 9; j++) {
			num = a[i][j];
			if (ch[num]) {
				return 0;
			}
			else {
				ch[num] = true;
			}
		}
	}
	//세로검사
	for (int j = 0; j < 9; j++) {
		memset(ch, false, sizeof(ch));
		for (int i = 0; i < 9; i++) {
			num = a[i][j];
			if (ch[num]) {
				return 0;
			}
			else {
				ch[num] = true;
			}
		}
	}
	//사각형 검사
	for (int stx = 0; stx < 9; stx += 3) {
		for (int sty = 0; sty < 9; sty += 3) {
			memset(ch, false, sizeof(ch));
			for (int i = stx; i < stx + 2; i++) {
				for (int j = sty; j < sty + 2; j++) {
					num = a[i][j];
					if (ch[num]) {
						return 0;
					}
					else {
						ch[num] = true;
					}
				}
			}
		}
	}
	return 1;
}


int main()
{	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		printf("#%d %d\n", t, search());
	}
	return 0;
}