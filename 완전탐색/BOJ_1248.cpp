#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;
char a[11][11];
int psum[11][11];
bool cleared;

void psumUpdater(int index, int value) {
	for (int i = 0; i <= index; i++) {
		for (int j = index; j < N; j++) {
			psum[i][j] += value;
		}
	}
}

bool validChecker(vector<int>& pick, int index) {
	for (int i = 0; i < index; i++) {
		for (int j = i; j < index; j++) {
			if (a[i][j] == '0' && psum[i][j] != 0) return false;
			if (a[i][j] == '-' && psum[i][j] >= 0) return false;
			if (a[i][j] == '+' && psum[i][j] <= 0) return false;
		}
	}
	return true;
}
void dfs(vector<int> pick, int index) {
	//test	
	/*
	printf("picked : ");
	for (int x : pick) {
	printf("%d ", x);
	}
	printf("\n");
	printf("psum : \n");
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	printf("%d ", psum[i][j]);
	}
	printf("\n");
	}
	*/
	if (cleared) return;
	if (!validChecker(pick, index)) return;
	//다구한경우.
	if (index == N) {
		cleared = true;
		for (int x : pick) {
			printf("%d ", x);
		}
		exit(0);
		return;
	}

	// 선택.
	if (a[index][index] == '0') {
		//0이면 무조건 0 (노빠꾸)
		pick.push_back(0);
		dfs(pick, index + 1);
	}
	else if (a[index][index] == '+') {
		//1~10중 하나.
		for (int i = 1; i <= 10; i++) {
			pick.push_back(i);
			psumUpdater(index, i);
			dfs(pick, index + 1);
			psumUpdater(index, -i);
			pick.pop_back();
		}
	}
	else {
		//-10 ~ -1 중 하나.
		for (int i = -10; i <= -1; i++) {
			pick.push_back(i);
			psumUpdater(index, i);
			dfs(pick, index + 1);
			psumUpdater(index, -i);
			pick.pop_back();
		}
	}
}

int main()
{
	scanf("%d", &N);
	memset(a, ' ', sizeof(a));
	char c;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> c;
			a[i][j] = c;
		}
	}
	vector<int> v;
	memset(psum, 0, sizeof(psum));
	cleared = false;
	dfs(v, 0);

	return 0;
}