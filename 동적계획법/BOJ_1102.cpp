#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int maxn = 16;
int cost[maxn][maxn];
bool state[maxn];
int dp[1 << maxn];
int n,p;

/* 
	�׸��� �ȵǴ����� 
	ex) 1�� �����ְ� 2,3,4,5�� �Ѿ��ϴ� ���.

	1��) 1->5 = 10 , 5->2 = 1, 2->3 = 1 , 3->4 = 1 �̰�
	2��) 1->2 = 5 , 2->3 = 5 , 3->4 = 5 , 4->5 = 5 �̸�

	�׸���� �� ���� 13�ڽ�Ʈ�� 1����Ʈ ��ſ� ���۽ÿ� �������� ���� 2����Ʈ�� �����ϰ� �ȴ�.
	���� dp�� Ǯ��� �Ѵ�.
*/

// ������°� ststus�̰� num���� �������϶� �߰��� �߻��ϴ� ���
int calcDp(int num, int status) { 
	if (num == p) {
		return 0;
	}
	int& ret = dp[status];
	if (ret != -1) return ret;

	ret = 987654321;

	// i->j
	for (int i = 0; i < n; i++) {
		//i�� �����ִ� ���
		if (status & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				// j�� �����ִ°��.
				if (!(status & (1 << j))) {
					ret = min(ret, calcDp((num + 1), status | (1 << j)) + cost[i][j]);
				}
			}
		}
	}
	return ret;

}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	string state_str;
	cin >> state_str;

	int now = 0;
	int current = 0;
	for (int i = 0; i < state_str.size(); i++) {
		if (state_str[i] == 'Y') {
			current = current | (1 << i);
			now++;
		}
	}
	scanf("%d", &p);

	if (now == 0) { // ��Ű�°��
		if (p == 0) printf("0"); // ���ѵ��Ǵ°��.
		else printf("-1"); // ��Ű�°��
	}
	else if (now >= p) { // ���ѵ��Ǵ°��.
		printf("0");
	}
	else {
		printf("%d", calcDp(now, current));
	}

	return 0;
}