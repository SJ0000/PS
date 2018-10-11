#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

//시간복잡도 : 


int D, W, K;
int a[14][21];
int t[14][21];
int ans;
//중복없이 n개를 고르는거. start부터 고를 수 있다.

//tmp의 line번째 줄을 val로 바꾼다.
void changer(int line, int val) {
	//test
//	printf("changer called : ");
//	printf("line : %d val : %d \n", line, val);
	//test-ed
	for (int i = 0; i < W; i++) {
		t[line][i] = val;
	}
}
bool checker() {
	//tmp가 합격기준에 통과하는지 check;
	int acnt, bcnt;
	for (int i = 0; i < W; i++) {
		acnt = bcnt = 1;
		for (int j = 0; j < D - 1; j++) {
			if (t[j][i] == 0 && t[j + 1][i] == 0) {
				bcnt = 1;
				acnt++;
			}
			else if (t[j][i] == 1 && t[j + 1][i] == 1) {
				acnt = 1;
				bcnt++;
			}
			else {
				acnt = bcnt = 1;
			}
			if (acnt == K || bcnt == K) break;
		}
		if (acnt < K && bcnt < K)return false;
	}
	return true;
}

void choice(int toPick, int start,  vector<int> picked) {
	//답이 정해진 경우.
	if (ans >= 0) return;
	//다 고른 경우. 처리하고 리턴
	if (toPick == picked.size()) {
		//약품을 a or b로 골라야 한다. 
		//i는 비트마스크 ex) 000 001 010 011 011
		//비트마스크가 0이면 b뿌리고 아니면 a 뿌린다. 

		//test
		/*
		printf("toPick : %d  : ",toPick);
		for (int x : picked) {
			printf("%d ", x);
		}		
		printf("\n");
		*/
		
		//test-ed

		for (int i = 0; i < (1 << toPick); i++) {
			memcpy(t, a, sizeof(t));
			for (int j = 0; j < toPick; j++) {
				//j번째꺼가 1이면 1로바꿈.
				if (i & (1 << j)) {
					changer(picked[j], 0);
				}
				else {
					changer(picked[j], 1);
				}
			}
			//약품을 바른게 성능테스트를 통과할 경우.

			//test
			/*
			printf("PRINT t Array : \n");
			for (int i = 0; i < D; i++) {
				for (int j = 0; j < W; j++) {
					printf("%d ", t[i][j]);
				}
				printf("\n");
			}
			*/
			if (checker()) {
				ans = toPick;
				return;
			}
		}		
		return;
	}
	//고르는거.
	for (int i = start; i < D; i++) {
		picked.push_back(i);
		choice(toPick, i + 1, picked);	
		picked.pop_back();
	}
}
int main(void) {
	int T;
	scanf("%d", &T);

	for(int t_case = 1; t_case <= T; t_case++) {
		scanf("%d %d %d", &D, &W, &K);
		ans = -1;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		vector<int> v;
		for (int i = 0; i <= D; i++) {
			choice(i, 0, v);
			if (ans >= 0) break;
		}
		printf("#%d %d\n", t_case, ans);
	}	
	return 0;
}