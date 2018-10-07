#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int a[17][17];
int N;
vector<int> choice,food_a,food_b;
int min_ab;
int getSynergy(vector<int> food) {
	int ret = 0;
	for (int x : food) {
		for (int y : food) {
			ret += a[x][y];
		}
	}
	return ret;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for(int t_case = 1; t_case <= T; t_case++) {
		min_ab = 987654321;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		//permutation�� choice
		//choice[i]�� 0�̸� A������ ���, 1�̸� B������ ���.
		choice.clear();
		for (int i = 0; i < N / 2; i++) {
			choice.push_back(0);
		}
		for (int i = 0; i < N / 2; i++) {
			choice.push_back(1);
		}
		do {
			//food_a,b�� �����Ḧ ���������� �ִ´�.
			food_a.clear(); food_b.clear();
			for (int i = 0; i < N; i++) {
				if (choice[i] == 0) {
					food_a.push_back(i);
				}
				else {
					food_b.push_back(i);
				}
			}
			min_ab = min(min_ab, abs(getSynergy(food_a) - getSynergy(food_b)));			
		} while (next_permutation(choice.begin(),choice.end()));	
		printf("#%d %d\n", t_case, min_ab);
	}
	return 0;
}