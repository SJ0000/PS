#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;

//"���� �տ������� �־��� ��"


int N, K, D;
int rule[10001][3]; // A,B,C;

void binarySearch() {
	//lo�� �Ұ���, hi�� ����
	int lo, hi, mid;
	long long cnt;
	lo = 1, hi = N;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) {
			//mid�� i�� ��Ģ�� ������ ���� ���
			//���� ����������.
			if (rule[i][1] < mid) {
				cnt += (rule[i][1] - rule[i][0]) / rule[i][2] + 1;
			}
			else if (rule[i][0] == mid) {
				//mid�� i�� ��Ģ�� �������� ���.
				//�������� 1�� �������ִ�.
				cnt++;
			}
			else if (rule[i][0] > mid) {
				//mid�� ���������� �������
				//���丮 ������
				continue;
			}
			else {
				//������, �������� ���� �߰��ΰ��
				cnt += (mid - rule[i][0]) / rule[i][2] + 1;
			}
		}
		//�����Ѱ��
		if (cnt >= D) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	printf("%d\n", hi);
}

int main()
{
	scanf("%d %d %d", &N, &K, &D);
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &rule[i][0], &rule[i][1], &rule[i][2]);
	}
	binarySearch();

	return 0;
}