#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, ans;
int  chess[16];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,1,-1 };


//�밢�� �˻縦 �� ü�� ������ ���μ��� ���̸� �̿��ؼ� �����Ҽ��ִ�.

bool validCheck(int i) {
	for (int j = 0; j < i; j++) {
		if (chess[j] == chess[i] || abs(chess[i] - chess[j]) == abs(i - j)) {
			return false;
		}
	}
	return true;
}
void dfs(int i) {
	if (i == N) {
		ans++;
	}
	else {
		for (int j = 0; j < N; j++) {
			chess[i] = j;
			if (validCheck(i)) {
				dfs(i + 1);
			}

		}
	}
}

int main()
{
	scanf("%d", &N);
	ans = 0;
	dfs(0);
	printf("%d\n", ans);
	return 0;
}