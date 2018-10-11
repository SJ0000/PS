#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

//�ð����⵵ : 


int D, W, K;
int a[14][21];
int t[14][21];
int ans;
//�ߺ����� n���� ���°�. start���� �� �� �ִ�.

//tmp�� line��° ���� val�� �ٲ۴�.
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
	//tmp�� �հݱ��ؿ� ����ϴ��� check;
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
	//���� ������ ���.
	if (ans >= 0) return;
	//�� �� ���. ó���ϰ� ����
	if (toPick == picked.size()) {
		//��ǰ�� a or b�� ���� �Ѵ�. 
		//i�� ��Ʈ����ũ ex) 000 001 010 011 011
		//��Ʈ����ũ�� 0�̸� b�Ѹ��� �ƴϸ� a �Ѹ���. 

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
				//j��°���� 1�̸� 1�ιٲ�.
				if (i & (1 << j)) {
					changer(picked[j], 0);
				}
				else {
					changer(picked[j], 1);
				}
			}
			//��ǰ�� �ٸ��� �����׽�Ʈ�� ����� ���.

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
	//���°�.
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