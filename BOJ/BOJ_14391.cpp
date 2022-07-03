#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

//�ܼ��ϰ� ���γ��� ���γ��� �߿� �ִ밪������ ��Ǯ��
// 1000
// 0001
// 0000
// 1000   - > 1000 + 1000 + 10 �� �ִ�.
//dfs����Ž��.

using namespace std;

int N, M;
string s[4];

bool check[4][4] = { false, };
int block[] = { 0,1,2,3,10,20,30 };
int ans = -1;

void dfs(int before) {
	int tmp;
	int x = -1, y = -1;
	//���� �� �� �ε����� ã�´�.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j]) {
				x = i; y = j;
				break;
			}
		}
		if (x != -1) break;
	}
	//�ٰ����.
	if (x == -1) {
		ans = max(ans, before);
		return;
	}
	bool full;
	//����
	for (int pos : block) {
		int bx = pos / 10;
		int by = pos % 10;
		full = false;
		//���� üũ
		if (0 <= x + bx && x + bx < N && 0 <= y + by && y + by < M) {
			//�ش��Ͽ� �̹� �ڸ��� �������� ���� �� ����.
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
			//��Ʈ��ŷ
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