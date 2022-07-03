#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
const int INF = 987654321;
const int MAXN = 12;
int N, K, M, L;
int pre[MAXN]; // pre[i] = i�� ������ ���������� ����
int classes[10]; //i��° �б⿡ �����Ǵ� ������ ����.
int cache[10][1 << MAXN];

int bitCount(int n) {
	int ret = 0;
	for (int i = 0; i < MAXN; i++) {
		if (n & (1 << i)) ret++;
	}
	return ret;
}

//�̹��бⰡ semester�̰�, ���ݱ��� ���� ������ ������ taken�϶�
//K�� �̻��� ������ ��� �������� �� �б⳪ �� �־�� �ϴ°�?
//�Ұ����Ѱ�� inf��ȯ.
int graduate(int semester, int taken) {

	//�̹� k�� �̻� ���� ���.
	if (bitCount(taken) >= K) {
		return 0;
	}
	//M�бⰡ �������,�� �Ұ����� ���.
	if (semester == M) {
		return INF;
	}
	// dynamic
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;

	ret = INF;
	//�̹��б⿡ ������ ���� �� �ȵ��� ������� ����.
	int canTake = (classes[semester] & ~taken);
	//�������� �ȵ����� �ɷ���.
	for (int i = 0; i < N; i++) {
		// i�� ���� ���� i�� ������ �������� �ʾ����鼭
		// i�� �������� �� �̼����� ���� ������ �ִ� ���.
		if (canTake & (1 << i) && (taken & pre[i]) != pre[i]) {
			canTake &= ~(1 << i); //i�� ������ cantake���� ����.
		}
	}
	//�� ������ ���κ������� ��ȸ.
	for (int take = canTake; take > 0; take = ((take - 1)&canTake)) {
		//L���� �ʰ��� ��� ����
		if (bitCount(take) > L) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	//�ƹ��͵� �ȵ�� ���
	ret = min(ret, graduate(semester + 1, taken));

	return ret;
}



int main()
{
	int tc; scanf("%d", &tc);
	while (tc-- > 0) {
		memset(pre, 0, sizeof(pre));
		memset(cache, -1, sizeof(cache));
		memset(classes, 0, sizeof(classes));
		scanf("%d %d %d %d", &N, &K, &M, &L);
		int ncnt, val;
		for (int i = 0; i < N; i++) {
			scanf("%d", &ncnt);
			for (int j = 0; j < ncnt; j++) {
				scanf("%d", &val);
				pre[i] |= (1 << val);
			}
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &ncnt);
			for (int j = 0; j < ncnt; j++) {
				scanf("%d", &val);
				classes[i] |= (1 << val);
			}
		}
		int ans = graduate(0, 0);
		if (ans == INF) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}